#include <sqlite3.h>
#include <cstdio>

int make_db() {
    sqlite3 *db;
   char *zErrMsg = 0;
   int rc;

   rc = sqlite3_open("/static/db/quiz-game.db", &db);

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return 0;
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }
   return sqlite3_close(db);
}