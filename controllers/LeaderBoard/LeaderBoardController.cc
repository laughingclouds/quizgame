#include "LeaderBoardController.h"

/** Serve the `/LeaderBoard` page
1. Query database for top scores
2. Calculate top five scores
3. Insert into view */
void LeaderBoardController::leaderBoardHome(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback) const {

    // Add code here

    auto resp = HttpResponse::newHttpViewResponse("LeaderBoardHome");
    callback(resp);
}