#pragma once

#include <drogon/HttpSimpleController.h>

class UserListController : public drogon::HttpSimpleController<UserListController> {
public:
  virtual void asyncHandleHttpRequest(
      const drogon::HttpRequestPtr &req,
      std::function<void(const drogon::HttpResponsePtr &)> &&callback) override;
  PATH_LIST_BEGIN
  PATH_ADD("/InformationList", drogon::Get);
  PATH_LIST_END
};
