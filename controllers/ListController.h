#pragma once

#include <drogon/HttpSimpleController.h>

class ListController : public drogon::HttpSimpleController<ListController> {
public:
  virtual void asyncHandleHttpRequest(
      const drogon::HttpRequestPtr &req,
      std::function<void(const drogon::HttpResponsePtr &)> &&callback) override;
  PATH_LIST_BEGIN
  // PATH_ADD("/", drogon::Get, drogon::Post);
  PATH_ADD("/list", drogon::Get);
  PATH_LIST_END
};
