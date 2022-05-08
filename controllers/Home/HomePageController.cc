#include <iostream>

#include "HomePageController.h"

#include "../utility/utils.hpp"

void HomePageController::homePage(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback) const {
	
  const std::string USER_NAME = req->getCookie("user");
	bool IS_USER_LOGGED_IN = isValidUserLoggedIn(req);

	HttpViewData data;

	data.insert("IS_USER_LOGGED_IN", IS_USER_LOGGED_IN);
  data.insert("USER_NAME", USER_NAME);

	//
	auto resp = HttpResponse::newHttpViewResponse("HomePage", data);
	callback(resp);
}