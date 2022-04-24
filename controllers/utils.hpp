#pragma once

#include "../models/models.hpp"
#include <drogon/drogon.h>
#include <string>

extern drogon::Cookie makeSecureCookie(std::string key, std::string value);

/** Check if a valid user is logged in. Return either true or false.
Throw InvalidSessionException if not the case.
Need to set `throwException` to `true` for exception.*/
extern bool isValidUserLoggedIn(const drogon::HttpRequestPtr &req,
                                bool throwException = false);

extern drogon_model::sqlite3::Solved makeSolvedObject(int questionId,
                                                      int userId);