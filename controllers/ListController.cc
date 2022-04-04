#include <drogon/HttpResponse.h>
#include <drogon/HttpTypes.h>

#include "ListController.h"

void ListController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback) {

  auto resp = drogon::HttpResponse::newHttpResponse();
  resp->setStatusCode(drogon::k200OK);
  resp->setContentTypeCode(drogon::CT_TEXT_CSS);
  resp->setBody("My controller list");
  callback(resp);
}
