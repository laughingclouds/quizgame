#include <drogon/HttpAppFramework.h>
#include <drogon/orm/Mapper.h>
#include <vector>

#include "../models/Category.h"
#include "QuizSettingController.h"

using namespace drogon_model;
using namespace drogon_model::sqlite3;

/** Feed all category data into the view */
void QuizSettingController::asyncHandleHttpRequest(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback) {
  // write your application logic here
  /** Get Category data from DB */
  std::vector<Category> categoryVec = orm::Mapper<Category>(app().getDbClient()).findAll();
  // categoryVec[0].getValueOfId();
	/** Insert "Category data" into "data"*/
  HttpViewData data;
	data.insert("categoryVec", categoryVec);

  auto resp = HttpResponse::newHttpViewResponse("QuizSetting.csp", data);
  callback(resp);
}
