#include <vector>

#include "../../exceptions/InvalidSession.hpp"
#include "StartGameController.h"

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