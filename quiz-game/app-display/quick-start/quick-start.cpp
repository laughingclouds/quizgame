#include <menu.h>

#include <array>
#include <string>

#include "../main-menu/main-menu.hpp"

namespace app_display_op {
namespace quick_start {
std::array<std::string, 6> choices = {"1. Quick Start", "2. Login",
                                      "3. Leaderboard", "4. New User",
                                      "5. Exit",        ""};

std::array<std::string, 6> choice_descriptions = {
    " 5 miscellanious questions",     " Login to save and continue with game",
    " Top scores by different users", " Add a new user",
    " Exit the application",          ""};

/*render the choice selected and its description below the menu*/
void show_choice_and_desc(MENU *menu, int x, int y);

/*render the WINDOW structure according to the given arguments*/
void print_window(WINDOW *win, int starty, int startx, int width,
                  std::string window_head, chtype color);

/**
Creates the "main menu" and allows user to select an option
win_y, win_x is starting point where main is rendered
sub_win_y, sub_win_x relative to main window coordinates

example: sub_win_x = 1 would mean first row of main window
**/
void render(int win_y, int win_x, int sub_win_y, int sub_win_x) {
  /* Create items */
  std::array<ITEM *, choices.size()> items;

  for (int i = 0; i < choices.size(); i++)
    items.at(i) =
        new_item(choices.at(i).c_str(), choice_descriptions.at(i).c_str());

  /* Create menu */
  MENU *menu = new_menu(items.data());
  // to not show the description
  menu_opts_off(menu, O_SHOWDESC);

  /* Create the window to be associated with the menu */
  WINDOW *menu_win = newwin(20, 20, win_y, win_x);
  keypad(menu_win, TRUE);

  /* Set main window and sub window */
  set_menu_win(menu, menu_win);
  set_menu_sub(menu, derwin(menu_win, 12, 18, sub_win_y, sub_win_x));

  /* Set menu mark to the string " ~> " */
  set_menu_mark(menu, " ~> ");

  /* Print a border around the main window and print a title */
  box(menu_win, 0, 0);

  print_window(menu_win, 0, 1, 50, "Main Menu", COLOR_PAIR(1));

  mvwaddch(menu_win, 2, 0, ACS_LTEE);
  mvwhline(menu_win, 2, 1, ACS_HLINE, 48);
  mvwaddch(menu_win, 2, 49, ACS_RTEE);

  mvprintw(0, win_y + 1, "F1 to exit");
  refresh();

  /* Post the menu */
  post_menu(menu);
  wrefresh(menu_win);

  // win_x - 1 to show text just above the window
  show_choice_and_desc(menu, win_y - 1, win_x + 1);
  
  int c;
  while ((c = wgetch(menu_win)) != KEY_F(1)) {
    switch (c) {
    case KEY_DOWN:
      menu_driver(menu, REQ_DOWN_ITEM);
      show_choice_and_desc(menu, win_y - 1, win_x + 1);
      break;
    case KEY_UP:
      menu_driver(menu, REQ_UP_ITEM);
      show_choice_and_desc(menu, win_y - 1, win_x + 1);
      break;
    case 10: // enter
      init_pair(1, COLOR_GREEN, COLOR_BLACK);
      /**
      this is where we further check what item was selected
      and create different windows based on them
       **/
      break;
    }
    wrefresh(menu_win);
  }

  /* Unpost and free all the memory taken up */
  unpost_menu(menu);
  free_menu(menu);

  for (ITEM *item : items)
    free_item(item);
}

void print_window(WINDOW *win, int starty, int startx, int width,
                  std::string window_head, chtype color) {
  int x, y;
  int temp;

  if (win == NULL)
    win = stdscr;
  getyx(win, y, x);

  if (startx != 0)
    x = startx;
  if (starty != 0)
    y = starty;
  if (width == 0)
    width = 80;

  temp = (width - window_head.length()) / 2;
  x = startx + temp;
  wattron(win, color);
  mvwprintw(win, y, x, "%s", window_head.c_str());
  wattroff(win, color);
  refresh();
}

void show_choice_and_desc(MENU *menu, int y, int x) {
  ITEM *cur_item = current_item(menu);
  move(x, 0);
  clrtoeol();
  //  item_index(cur_item)  // index of the item
  mvprintw(y, x, "%s:\t %s", item_name(cur_item),
           item_description(cur_item));

  refresh();
  pos_menu_cursor(menu);
}
} // namespace quick_start
} // namespace app_display_op