#include <iostream>
#include <string>
#include <sqlite3.h>

#include "quiz-game.hpp"


namespace dbinfo {
  std::string DATA_DIR = std::string("data");
  std::string DB_NAME = std::string("test.sqlite3");
}

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

int main() {
  clear_screen();
  std::cout << "Hello World!" << '\n';

  std::cout << NAME << '\n';
  std::cout << "Release: " << RELEASE << '\n';
  std::cout << "Version: " << VERSION << std::endl;

  create_testdb();
}