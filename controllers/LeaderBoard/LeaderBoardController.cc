#include "LeaderBoardController.h"
#include "../../models/models.hpp"

using namespace drogon_model;
using namespace drogon_model::sqlite3;

/** Serve the `/LeaderBoard` page
1. Query database for top scores
2. Calculate top five scores
3. Insert into view */
void LeaderBoardController::leaderBoardHome(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback) const {

  // orderBy: colum score, in descending
  // limit: the search results to only 5
  // offset: from where to start querying data from
  // User "No Name" lies at row 0 of the database
  auto ormUsersTopScorers =
      orm::Mapper<User>(app().getDbClient())
          .orderBy(User::Cols::_score, orm::SortOrder::DESC)
          .limit(5)
          .offset(1)
          .findAll();

  HttpViewData data;

  data.insert("ormUsersTopScorers", ormUsersTopScorers);

  auto resp = HttpResponse::newHttpViewResponse("LeaderBoardHome", data);
  callback(resp);
}