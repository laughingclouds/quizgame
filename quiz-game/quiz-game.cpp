#include <curses.h>
#include <iostream>
#include <menu.h>

#include <array>
#include <string>

#include "app-display/main-menu/main-menu.hpp"

int main() {
  /* Initialize curses */
  initscr();
  start_color();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  init_pair(1, COLOR_RED, COLOR_BLACK);

  app_display_op::main_menu::render_and_operate(4, 4, 3, 1, 50);

  endwin();
  return 0;
}