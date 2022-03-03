#include <iostream>
#include <sqlite3.h>

#include "quiz-game.hpp"

#define DATA_DIR "data/"

using namespace std;

void create_testdb() {
  sqlite3 *db;
  int rc;

  rc = sqlite3_open("test.db", &db);

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