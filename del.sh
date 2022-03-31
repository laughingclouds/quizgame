ARGS="-std=c++17 -Wall -Wextra";
LIBS="-lmenu -lncurses -lsqlite3";
DEPS="quiz-game/app-display/main-menu/main-menu.cpp quiz-game/app-display/quick-start/quick-start.cpp"
clang++-12 $ARGS quiz-game/quiz-game.cpp $DEPS $LIBS;
