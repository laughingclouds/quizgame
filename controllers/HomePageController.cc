#include "HomePageController.h"
#include <drogon/HttpViewData.h>

#include "utils.hpp"

void HomePageController::homePage(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback) const {
	
	bool IS_USER_LOGGED_IN = isValidUserLoggedIn(req);

	HttpViewData data;

	data.insert("IS_USER_LOGGED_IN", IS_USER_LOGGED_IN);
	//
	auto resp = HttpResponse::newHttpViewResponse("HomePage.csp", data);
	callback(resp);
}