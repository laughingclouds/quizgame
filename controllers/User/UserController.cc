#include "UserController.h"

#include "../../models/models.hpp"

// Simply serve the form that takes username and password
void UserController::ServeAddUserForm(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback) const {
    auto resp = HttpResponse::newHttpViewResponse("AddUserForm");
    callback(resp);
}

/** Take input from submitted from and create a user in the database
and redirect to home page*/
void UserController::CreateUser(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback) const {
    auto resp = HttpResponse::newHttpResponse();
    resp->setBody("New User Created!");
    callback(resp);
}