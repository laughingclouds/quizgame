#include <drogon/HttpAppFramework.h>
#include <drogon/HttpResponse.h>
#include <drogon/HttpTypes.h>
#include <drogon/drogon.h>
#include <drogon/utils/FunctionTraits.h>
#include <functional>

#include "create_test_db.cc"

using namespace drogon;
int main() {
  make_db();
  app().registerHandler(
      "/", [](const HttpRequestPtr &req,
               std::function<void(const HttpResponsePtr &)> &&callback) {
        auto resp = HttpResponse::newHttpViewResponse("quiz_game_home.csp");
        callback(resp);
      });
  
  app().registerHandler(
      "/StartGame", [](const HttpRequestPtr &req,
               std::function<void(const HttpResponsePtr &)> &&callback) {
        auto resp = HttpResponse::newHttpViewResponse("quiz_game_start.csp");
        callback(resp);
      });

  app().registerHandler(
      "/list_para",
      [=](const HttpRequestPtr &req,
          std::function<void(const HttpResponsePtr &)> &&callback) {
        auto para = req->getParameters();
        HttpViewData data;
        data.insert("title", "ListParameters");
        data.insert("parameters", para);
        auto resp =
            HttpResponse::newHttpViewResponse("ListParameters.csp", data);
        callback(resp);
      });
  // Set HTTP listener address and port
  drogon::app().addListener("0.0.0.0", 8080);
  // Load config file
  // drogon::app().loadConfigFile("../config.json");
  // Run HTTP framework,the method will block in the internal event loop
  drogon::app().run();
  return 0;
}
