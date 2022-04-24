#include <drogon/HttpTypes.h>
#include <drogon/drogon.h>
#include <iostream>
#include <string>

#include "../exceptions/InvalidSession.hpp"
#include "../models/models.hpp"

// Make cookies that persist for all pages
drogon::Cookie makeSecureCookie(std::string key, std::string value) {
  auto cookie = drogon::Cookie(key, value);
  cookie.setSecure(true);
  cookie.setPath("/");
  return cookie;
}

/** Check if a valid user is logged in. Return either true or false.
Throw InvalidSessionException if not the case.
Need to set `throwException` to `true` for exception.*/
bool isValidUserLoggedIn(const drogon::HttpRequestPtr &req,
                         bool throwException = false) {
  bool isValid = false;
  auto cookie = req->getCookie("userId");

  if (cookie != "0" and cookie != " " and cookie != "")
    isValid = true;
  else if (throwException and !isValid)
    throw InvalidSessionException();
  return isValid;
}

drogon_model::sqlite3::Solved makeSolvedObject(int questionId, int userId) {
  auto ormSolved = drogon_model::sqlite3::Solved();
  ormSolved.setQuestionId(questionId);
  ormSolved.setUserId(userId);

  return ormSolved;
}