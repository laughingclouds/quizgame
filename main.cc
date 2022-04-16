#include <drogon/HttpAppFramework.h>
#include <drogon/orm/DbClient.h>
#include <drogon/orm/SqlBinder.h>
#include <sqlite3.h>
#include <drogon/drogon.h>

#include "models/Category.h"
#include "models/User.h"

int main() {
  using namespace drogon;
  
  std::cout << "Server started!\n";
  
  app().registerHandler(
      "/", [](const HttpRequestPtr &req,
              std::function<void(const HttpResponsePtr &)> &&callback) {
        auto resp = HttpResponse::newHttpViewResponse("quiz_game_home.csp");
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
  app().addListener("0.0.0.0", 8080);
  // Load config file
  drogon::app().loadConfigFile("../config.json");
  // Run HTTP framework,the method will block in the internal event loop
  app().run();
  // ::dbPtr = drogon::orm::DbClient::newSqlite3Client("main", 1);
  return 0;
}
