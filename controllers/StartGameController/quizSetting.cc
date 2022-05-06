#include "StartGameController.h"

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