#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class LeaderBoardController
    : public drogon::HttpController<LeaderBoardController> {
public:
  METHOD_LIST_BEGIN
  ADD_METHOD_TO(LeaderBoardController::leaderBoardHome, "/LeaderBoard", Get,
                Post);

  METHOD_LIST_END
  void leaderBoardHome(
      const HttpRequestPtr &req,
      std::function<void(const HttpResponsePtr &)> &&callback) const;
};
