#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class UserListController : public HttpSimpleController<UserListController> {
public:
  virtual void asyncHandleHttpRequest(
      const HttpRequestPtr &req,
      std::function<void(const HttpResponsePtr &)> &&callback) override;
  PATH_LIST_BEGIN
  PATH_ADD("/InformationList", Get);
  PATH_LIST_END
};
