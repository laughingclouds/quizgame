#pragma once

#include <drogon/HttpController.h>
#include <drogon/HttpTypes.h>

using namespace drogon;

class StartGameController : public drogon::HttpController<StartGameController> {
public:
  METHOD_LIST_BEGIN
  // use METHOD_ADD to add your custom processing function here;
  // METHOD_ADD(StartGameController::get, "/{2}/{1}", Get); // path is
  // /StartGameController/{arg2}/{arg1}
  // METHOD_ADD(StartGameController::your_method_name, "/{1}/{2}/list", Get); //
  // path is /StartGameController/{arg1}/{arg2}/list
  ADD_METHOD_TO(StartGameController::startGameBasedOnCategoryId,
             "/StartGame?category_id={1}", Get);
  METHOD_LIST_END
  /*
  your declaration of processing function maybe like this:
  void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2); 
  void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback,
  double p1, int p2) const;
  */

  void startGameBasedOnCategoryId(
      const HttpRequestPtr &req,
      std::function<void(const HttpResponsePtr &)> &&callback,
      int category_id) const;
};
