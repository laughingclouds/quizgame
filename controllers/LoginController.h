#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class LoginController : public drogon::HttpController<LoginController> {
public:
  METHOD_LIST_BEGIN

  ADD_METHOD_TO(LoginController::userLogin, "/Login", Get, Post);
  ADD_METHOD_TO(LoginController::userLogout, "/Logout", Get, Post);
  ADD_METHOD_TO(LoginController::evaluateUserCredentials, "/EvaluateCredentials", Get, Post);

  METHOD_LIST_END

  /** Simply serve the login page to enter details */
  void userLogin(const HttpRequestPtr &req,
                 std::function<void(const HttpResponsePtr &)> &&callback) const;

  /** Check username and password against database.
  Redirect to home page on success.
  Redirect to Login page if error. */
  void evaluateUserCredentials(const HttpRequestPtr &req,
                 std::function<void(const HttpResponsePtr &)> &&callback) const;

  /** Simply set user to None and userId to 0*/
  void userLogout(const HttpRequestPtr &req,
                 std::function<void(const HttpResponsePtr &)> &&callback) const;
};
