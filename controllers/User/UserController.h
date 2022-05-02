#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class UserController : public drogon::HttpController<UserController>
{
  public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(UserController::ServeAddUserForm, "/AddUser", Get, Post);
    ADD_METHOD_TO(UserController::CreateUser, "/AddUser/CreateUser", Post);
    METHOD_LIST_END
    
    // Simply serve the form that takes username and password
    void ServeAddUserForm(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) const;
    // Take input from submitted from and create a user in the database
    void CreateUser(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) const;
};
