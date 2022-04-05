#include <cctype>
#include <iostream>
#include <string>
#include <vector>

#include <drogon/HttpResponse.h>
#include <drogon/HttpTypes.h>
#include <drogon/HttpViewData.h>

#include "../models/User.h"
#include "../models/Question.h"
#include "../models/Category.h"
#include "UserListController.h"

using namespace drogon;
using namespace drogon_model;
using namespace drogon_model::sqlite3;

template <class T> std::vector<T> getModelObjectVec() {
  return orm::Mapper<T>(app().getDbClient()).findAll();
}

std::string titilize(std::string str) {
  // converting first character to uppercase
  str[0] = std::toupper(str[0]);
  return str;
}

void UserListController::asyncHandleHttpRequest(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback) {

  /** Make vector of objects, then vector of their text values */
  std::vector<User> userVec = getModelObjectVec<User>();
  std::vector<std::string> userNameVec;

  std::vector<Question> questionVec = getModelObjectVec<Question>();
  std::vector<std::string> questionTxtVec;

  std::vector<Category> categoryVec = orm::Mapper<Category>(app().getDbClient()).findAll();
  std::vector<std::string> categoryNameVec;

  /** Initialize vector of text values */
  for (auto userObj : userVec)
    userNameVec.push_back(titilize(userObj.getValueOfName()));
  
  for (auto quesObj : questionVec)
    questionTxtVec.push_back(quesObj.getValueOfText());

  for (auto categObj : categoryVec)
    categoryNameVec.push_back(categObj.getValueOfName());
  
  /** Insert text values into `data` */
  HttpViewData data;
  data.insert("userNameVec", userNameVec);
  data.insert("questionTxtVec", questionTxtVec);
  data.insert("categoryNameVec", categoryNameVec);

  auto resp = HttpResponse::newHttpViewResponse("InformationList.csp", data);
  callback(resp);
}
