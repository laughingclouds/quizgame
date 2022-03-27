#include <string>
#include <unistd.h>

#include "../../quiz-game.hpp"
#include "../../custom_types.hpp"
#include "../display_operations/display_operations.hpp"
#include "../terminal_operations/terminal_ops.hpp"

namespace app_display_op {
namespace input {

std::string _prompt(char *prompt, void (*callback)(char *, int)) {
  size_t bufsize = 128;
  std::string buf = "";

  size_t buflen = 0;
  buf += '\0';

  while (1) {
    app_display_op::setStatusMessage(prompt, buf.c_str());
    // setStatusMessage(prompt, buf.c_str());
    app_display_op::refreshScreen();
    // refreshScreen();


    int c = terminal::readKey();
    if (c == DEL_KEY || c == CTRL_KEY('h') || c == BACKSPACE) {
      if (buf.length() != 0)
        buf[-1] = '\0';
    } else if (c == '\x1b') {
      setStatusMessage("");
      if (callback)
        callback(&buf[0], c);
      return NULL;
    } else if (c == '\r') {
      if (buf.length() != 0) {
        setStatusMessage("");
        if (callback)
          callback(&buf[0], c);
        return buf;
      }
    } else if (!iscntrl(c) && c < 128) {
      //   if (buflen == bufsize - 1) {
      //     bufsize *= 2;
      //     buf = realloc(buf, bufsize);
      //   }
      buf += c + '\0';
    }

    if (callback)
      callback(&buf[0], c);
  }
}

void moveCursor(int key) {
  erow *row = (E.cy >= E.numrows) ? NULL : &E.row[E.cy];

  switch (key) {
  case ARROW_LEFT:
    if (E.cx != 0) {
      E.cx--;
    } else if (E.cy > 0) {
      E.cy--;
      E.cx = E.row[E.cy].size;
    }
    break;
  case ARROW_RIGHT:
    if (row && E.cx < row->size) {
      E.cx++;
    } else if (row && E.cx == row->size) {
      E.cy++;
      E.cx = 0;
    }
    break;
  case ARROW_UP:
    if (E.cy != 0) {
      E.cy--;
    }
    break;
  case ARROW_DOWN:
    if (E.cy < E.numrows) {
      E.cy++;
    }
    break;
  }

  row = (E.cy >= E.numrows) ? NULL : &E.row[E.cy];
  int rowlen = row ? row->size : 0;
  if (E.cx > rowlen) {
    E.cx = rowlen;
  }
}

void processKeypress() {
  static int quit_times = APP_QUIT_TIMES;

  int c = terminal::readKey();

  switch (c) {
  case '\r':
    _row::insertNewline();
    break;

  case CTRL_KEY('q'):
    if (E.dirty && quit_times > 0) {
      setStatusMessage("WARNING!!! File has unsaved changes. "
                                       "Press Ctrl-Q %d more times to quit.",
                                       quit_times);
      quit_times--;
      return;
    }
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);
    exit(0);
    break;

  case CTRL_KEY('s'):
    // editorSave();
    break;

  case HOME_KEY:
    E.cx = 0;
    break;

  case END_KEY:
    if (E.cy < E.numrows)
      E.cx = E.row[E.cy].size;
    break;

  case CTRL_KEY('f'):
    // editorFind();
    break;

  case BACKSPACE:
  case CTRL_KEY('h'):
  case DEL_KEY:
    if (c == DEL_KEY)
      moveCursor(ARROW_RIGHT);
    // editorDelChar();
    break;

  case PAGE_UP:
  case PAGE_DOWN: {
    if (c == PAGE_UP) {
      E.cy = E.rowoff;
    } else if (c == PAGE_DOWN) {
      E.cy = E.rowoff + E.screenrows - 1;
      if (E.cy > E.numrows)
        E.cy = E.numrows;
    }

    int times = E.screenrows;
    while (times--)
      moveCursor(c == PAGE_UP ? ARROW_UP : ARROW_DOWN);
  } break;

  case ARROW_UP:
  case ARROW_DOWN:
  case ARROW_LEFT:
  case ARROW_RIGHT:
    moveCursor(c);
    break;

  case CTRL_KEY('l'):
  case '\x1b':
    break;

  default:
    _row::insertChar(c);
    // editorInsertChar(c);
    break;
  }

  quit_times = APP_QUIT_TIMES;
}
} // namespace input
} // namespace app_display_op