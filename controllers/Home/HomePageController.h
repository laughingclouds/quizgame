#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class HomePageController : public drogon::HttpController<HomePageController> {
public:

  METHOD_LIST_BEGIN

  ADD_METHOD_TO(HomePageController::homePage, "/", Get, Post);

  METHOD_LIST_END

  void homePage(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback) const;
};
