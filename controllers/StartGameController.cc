#include "StartGameController.h"
#include "../models/Category.h"

using namespace drogon_model;
using namespace drogon_model::sqlite3;

void StartGameController::startGameBasedOnCategoryId(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback,
    int category_id) const {

  try {
    Category catObj = orm::Mapper<Category>(app().getDbClient())
                          .findByPrimaryKey(category_id);

    HttpViewData data;

    data.insert("catObj", catObj);

    auto resp = HttpResponse::newHttpViewResponse("StartGame.csp", data);
    callback(resp);

  } catch (orm::UnexpectedRows err) {
    /*This means that the path requested is "/StartGame?"
    This means there is no input.

    In this case, redirect user to "/QuizSetting" to select a category
    https://developer.mozilla.org/en-US/docs/Web/HTTP/Status/300
    */
    auto resp = HttpResponse::newRedirectionResponse("/QuizSetting", k300MultipleChoices);
    callback(resp);
  }
}
