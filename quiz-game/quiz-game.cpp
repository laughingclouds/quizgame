#include <iostream>
#include <sqlite3.h>
#include <string>

#include "quiz-game.hpp"

using std::cout;
using std::endl;

namespace dbinfo {
  using std::string;
  string DATA_DIR = string("data");
  string DB_NAME = string("test.db");
}

void create_testdb() {
  
  sqlite3 *db;
  int rc;

  rc = sqlite3_open(dbinfo::DB_NAME.c_str(), &db);

  if (rc) {
    cout << "Couldn't open database: " << sqlite3_errmsg(db);
    cout << endl;
  } else {
    cout << "Database opened successfully\n";
  }
  sqlite3_close(db);
}

int main() {
  clear_screen();
  cout << "Hello World!" << '\n';

  cout << NAME << '\n';
  cout << "Release: " << RELEASE << '\n';
  cout << "Version: " << VERSION << endl;

  create_testdb();
}