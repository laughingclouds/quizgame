#include <drogon/HttpAppFramework.h>
#include <drogon/HttpTypes.h>
#include <drogon/orm/Criteria.h>
#include <iostream>
#include <stdexcept>
#include <string>

#include "LoginController.h"
#include <drogon/orm/Exception.h>
#include <drogon/orm/Mapper.h>

#include "../models/models.hpp"

#include "utils.hpp"
#include "../exceptions/InvalidSession.hpp"

using namespace drogon_model;
using namespace drogon_model::sqlite3;

void LoginController::userLogin(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback) const {
  auto resp = HttpResponse::newHttpViewResponse("Login.csp");
  callback(resp);
}

void LoginController::userLogout(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback) const {
  
  auto redir = HttpResponse::newRedirectionResponse("/", k303SeeOther);
  redir->addCookie(makeSecureCookie("user", "None"));
  redir->addCookie(makeSecureCookie("userId", "0"));
  callback(redir);
}

void LoginController::evaluateUserCredentials(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback) const {

  if (req->getMethod() == drogon::Get) {
    auto redir = HttpResponse::newRedirectionResponse("/Login", k303SeeOther);
    callback(redir);
  }

  try {
    std::string username = req->getParameter("username");
    std::string password = req->getParameter("password");

    if (username == "None" or username == "No Name" or username == "")
      throw orm::UnexpectedRows("User does not exist in database");

    auto ormUser =
        orm::Mapper<User>(app().getDbClient())
            .findBy(orm::Criteria("name", orm::CompareOperator::EQ, username))
            .at(0);

    if (ormUser.getValueOfPassword() != password)
      throw orm::UnexpectedRows("Wrong Password");

    auto resp = HttpResponse::newRedirectionResponse("/", k303SeeOther);

    resp->addCookie(makeSecureCookie("user", username));
    resp->addCookie(
        makeSecureCookie("userId", std::to_string(ormUser.getValueOfId())));

    callback(resp);

  } catch (orm::UnexpectedRows err) {

    auto redir = HttpResponse::newRedirectionResponse("/Login");
    callback(redir);

  } catch (std::out_of_range err) {
  
    auto redir = HttpResponse::newRedirectionResponse("/Login");
    callback(redir);
    
  }
}