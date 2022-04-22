#include "StartGameController.h"
#include "../models/Category.h"
#include "../models/Option.h"
#include "../models/Question.h"

#include "quizModels.hpp"
#include <drogon/HttpAppFramework.h>

using namespace drogon_model;
using namespace drogon_model::sqlite3;

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
    if (category_id == 0)
      throw orm::UnexpectedRows("Given category ID is not accepted.");

    Category catObj = orm::Mapper<Category>(app().getDbClient())
                          .findByPrimaryKey(category_id);
    // orm::Mapper<Question>(app().getDbClient()).findBy(orm::Criteria(orm::CompareOperator::EQ));
    // vector<Question>
    auto ormQuestionVec =
        orm::Mapper<Question>(app().getDbClient())
            .findBy(orm::Criteria("categoryId", orm::CompareOperator::EQ,
                                  category_id));
    // ormQuestionVec[0].;

    HttpViewData data;

    data.insert("catObj", catObj);
    data.insert("ormQuestionVec", ormQuestionVec);

    auto resp = HttpResponse::newHttpViewResponse("StartGame.csp", data);
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
  }
}

void StartGameController::gameSubmission(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback) const {
  auto resp =
      HttpResponse::newRedirectionResponse("/QuizSetting", k300MultipleChoices);
  callback(resp);
}