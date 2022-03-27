#include <iostream>
#include <sqlite3.h>
#include <string>

#include "quiz-game.hpp"
#include "custom_types.hpp"
#include "app_display/app_display.hpp"

namespace dbinfo {
std::string DATA_DIR = "data";
std::string DB_NAME = "test.sqlite3";
} // namespace dbinfo

void create_testdb() {

  sqlite3 *db;
  int rc;

  rc = sqlite3_open(dbinfo::DB_NAME.c_str(), &db);

  if (rc) {
    std::cout << "Couldn't open database: " << sqlite3_errmsg(db);
    std::cout << std::endl;
  } else {
    std::cout << "Database opened successfully\n";
  }
  sqlite3_close(db);
}

struct appConfig E;

void initApp() {
  E.cy = 0;
  E.cy = 0;
  E.rx = 0;
  E.rowoff = 0;
  E.coloff = 0;
  E.numrows = 0;
  E.row = NULL;
  E.dirty = 0;
  E.filename = NULL;
  E.statusmsg[0] = '\0';
  E.statusmsg_time = 0;

  if (app_display_op::terminal::getWindowSize(&E.screenrows, &E.screencols) ==
      -1)
    app_display_op::terminal::die("getWindowSize");
  E.screenrows -= 2;
}

int main(int argc, char *argv[]) {

  app_display_op::terminal::enableRawMode();
  initApp();

  // clear_screen();

  app_display_op::setStatusMessage(
      "HELP: Ctrl-S = save | Ctrl-Q = quit | Ctrl-F = find");

  while (1) {
    app_display_op::refreshScreen();
  }
  // std::cout << "Hello World!" << '\n';

  // std::cout << NAME << '\n';
  // std::cout << "Release: " << RELEASE << '\n';
  // std::cout << "Version: " << VERSION << std::endl;

  // create_testdb();
}