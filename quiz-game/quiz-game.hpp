#pragma once

/**
For basic application settings
**/
#pragma once

#include "../version.hpp"

#define CTRL_KEY(k) ((k)&0x1f)
#define ABUF_INIT                                                              \
  { NULL, 0 }
#define TAB_STOP 8
#define APP_QUIT_TIMES 3

extern struct termios orig_termios;