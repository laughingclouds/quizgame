#pragma once

namespace app_display_op {
namespace terminal {
void die(const char *c);
// void enableRawMode();
/*Deal with low level terminal input*/
char readKey();
} // namespace terminal
} // namespace app_display_op