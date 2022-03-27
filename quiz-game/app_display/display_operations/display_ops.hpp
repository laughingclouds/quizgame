#pragma once

namespace app_display_op {
/*| used in kilo*/
void refreshScreen();

/*| used in fileio kilo*/
void setStatusMessage(const char *fmt, ...);

void insertChar(int c);
} // namespace output