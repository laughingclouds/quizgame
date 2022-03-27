#pragma once

namespace app_display_op {
namespace terminal {
/*| used in kilo*/
void die(const char *s);

/*| used in kilo*/
void enableRawMode();

/*| used in input*/
int readKey();

/*| used in kilo*/
int getWindowSize(int *rows, int *cols);
} // namespace terminal
} // namespace app_display_op