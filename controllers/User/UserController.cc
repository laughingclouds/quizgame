#include "UserController.h"

#include "../../models/models.hpp"

using namespace drogon_model;
using namespace drogon_model::sqlite3;

// Simply serve the form that takes username and password
void UserController::ServeAddUserForm(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback) const {
  auto resp = HttpResponse::newHttpViewResponse("AddUserForm");
  callback(resp);
}

/** Take input from submitted from and create a user in the database
and redirect to home page*/
void UserController::CreateUser(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback) const {
  
  auto parameters = req->getParameters();

	// Create user object and set attributes
  auto ormUser = User();
  ormUser.setName(parameters.at("username"));
  ormUser.setPassword(parameters.at("password"));
	ormUser.setScore(0); // this should've been set by default iirc
	
	// Insert object into the database
  orm::Mapper<User>(app().getDbClient()).insert(ormUser);

  auto resp = HttpResponse::newRedirectionResponse("/", k303SeeOther);
  callback(resp);
}