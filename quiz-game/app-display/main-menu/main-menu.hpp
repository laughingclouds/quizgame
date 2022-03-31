#pragma once

namespace app_display_op {
namespace main_menu {
/**
Creates the "main menu" and allows user to select an option
win_y, win_x is starting point where main is rendered
sub_win_y, sub_win_x relative to main window coordinates

example: sub_win_x = 1 would mean first row of main window
**/
void render_and_operate(int win_y, int win_x, int sub_win_y, int sub_win_x, int main_menu_width);
} // namespace main_menu
} // namespace app_display_op