#include <iostream>
#include <string>
#include <vector>

#include "StartGameController.h"

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

      auto ormSolvedVec =
          orm::Mapper<Solved>(app().getDbClient())
              .findBy(orm::Criteria("user_id", userId) &&
                      orm::Criteria("question_id", question.getValueOfId()));

      if (ormSolvedVec.size() == 0) {
        auto ormSolved = makeSolvedObject(question.getValueOfId(), userId);
        orm::Mapper<Solved>(app().getDbClient()).insert(ormSolved);
      }
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