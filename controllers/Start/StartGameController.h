#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class StartGameController : public drogon::HttpController<StartGameController> {
public:
  METHOD_LIST_BEGIN

  ADD_METHOD_TO(StartGameController::quizSetting, "/QuizSetting", Get, Post);
  
  ADD_METHOD_TO(StartGameController::startGameBasedOnCategoryId,
                "/StartGame?category_id={1}", Get);
  ADD_METHOD_TO(StartGameController::gameSubmission, "/StartGame/Score", Post);

  METHOD_LIST_END

  void quizSetting(
      const HttpRequestPtr &req,
      std::function<void(const HttpResponsePtr &)> &&callback) const;
  
  void startGameBasedOnCategoryId(
      const HttpRequestPtr &req,
      std::function<void(const HttpResponsePtr &)> &&callback,
      int category_id) const;
  
  void gameSubmission(
      const HttpRequestPtr &req,
      std::function<void(const HttpResponsePtr &)> &&callback) const;
};
