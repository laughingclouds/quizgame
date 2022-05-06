#include <iostream>
#include <string>
#include <vector>

#include "../../exceptions/InvalidSession.hpp"
#include "../../models/models.hpp"
#include "../utility/quizModels.hpp"
#include "../utility/utils.hpp"
#include "StartGameController.h"

using namespace drogon_model;
using namespace drogon_model::sqlite3;

void StartGameController::quizSetting(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback) const {

  if (!isValidUserLoggedIn(req)) {
    auto redir = HttpResponse::newRedirectionResponse("/Login", k303SeeOther);
    callback(redir);
  }
  /** Get Category data from DB */
  auto categoryVec = orm::Mapper<Category>(app().getDbClient()).findAll();

  HttpViewData data;
  data.insert("categoryVec", categoryVec);

  auto resp = HttpResponse::newHttpViewResponse("QuizSetting", data);
  callback(resp);
}

/**
User is provided with a form, that has a number of questions and their options.
After submission, the questionId and the correspoding responseId will be posted.
If responseId is the same as Question(quesionId).answerId, user is given a
point.
*/
void StartGameController::startGameBasedOnCategoryId(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback,
    int category_id) const {

  try {
    isValidUserLoggedIn(req, true);
    if (category_id == 0)
      throw orm::UnexpectedRows("Given category ID is not accepted.");

    Category catObj = orm::Mapper<Category>(app().getDbClient())
                          .findByPrimaryKey(category_id);

    auto ormQuestionVec =
        orm::Mapper<Question>(app().getDbClient())
            .findBy(orm::Criteria("categoryId", orm::CompareOperator::EQ,
                                  category_id));

    std::vector<quiz::Question> questions;

    for (auto ormQuestion : ormQuestionVec)
      questions.push_back(quiz::Question(ormQuestion));

    // shuffle the quiz::Question objects in a random order
    std::shuffle(questions.begin(), questions.end(), randomEngine);
    HttpViewData data;

    data.insert("catObj", catObj);
    data.insert("questions", questions);

    auto resp = HttpResponse::newHttpViewResponse("StartGame", data);
    callback(resp);

  } catch (orm::UnexpectedRows err) {
    /*This means that the path requested is "/StartGame?"
    This means there is no input.

    In this case, redirect user to "/QuizSetting" to select a category
    https://developer.mozilla.org/en-US/docs/Web/HTTP/Status/300
    */
    auto resp = HttpResponse::newRedirectionResponse("/QuizSetting",
                                                     k300MultipleChoices);
    callback(resp);

  } catch (InvalidSessionException err) {

    auto resp =
        HttpResponse::newRedirectionResponse("/Login", drogon::k303SeeOther);
    callback(resp);
  }
}

void StartGameController::gameSubmission(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback) const {

  int userId = std::stoi(req->getCookie("userId"));
  int number_of_correctly_answered_questions = 0;
  int number_of_questions = 0;

  std::vector<quiz::Answer> answers;

  auto paramemters = req->getParameters();
  for (auto param : paramemters) {
    number_of_questions++;

    auto question = orm::Mapper<Question>(app().getDbClient())
                        .findByPrimaryKey(std::stoi(param.first));

    answers.push_back(quiz::Answer(question));

    if (question.getValueOfAnswerid() == std::stoi(param.second)) {
      number_of_correctly_answered_questions++;

      auto ormSolved = makeSolvedObject(question.getValueOfId(), userId);
      orm::Mapper<Solved>(app().getDbClient()).insert(ormSolved);
    }
  }

  auto ormUser =
      orm::Mapper<User>(app().getDbClient()).findByPrimaryKey(userId);
  ormUser.setScore(ormUser.getValueOfScore() +
                   number_of_correctly_answered_questions);
  
  // saving changes to the user score
  orm::Mapper<User>(app().getDbClient()).update(ormUser);

  HttpViewData data;

  data.insert("number_of_questions", number_of_questions);
  data.insert("number_of_correctly_answered_questions",
              number_of_correctly_answered_questions);
  data.insert("answers", answers);

  auto resp = HttpResponse::newHttpViewResponse("GameScore", data);

  resp->addCookie(makeSecureCookie(
      "score", std::to_string(number_of_correctly_answered_questions)));

  callback(resp);
}