#include <menu.h>

#include "../quick-start/quick-start.hpp"

void process_selected_option(MENU *menu, int win_y, int win_x, int sub_win_y,
                             int sub_win_x) {
  int item_index = current_item(menu)->index;

  switch (item_index) {
    // quick start
  case 0:
    app_display_op::quick_start::render(win_y, win_x, sub_win_y, sub_win_x);
    break;
  // login
  case 1:
  // new user
  case 2:
  // exit
  case 3:;
  }
}