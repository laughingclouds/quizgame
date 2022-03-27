#include <cstring>
#include <iostream>
#include <cstdarg>

#include "../../quiz-game.hpp"
#include "../display_operations/row_ops.hpp"
#include "../buffer_operations/buffer_ops.hpp"

namespace app_display_op {

  void editorInsertNewline() {
  if (E.cx == 0) {
    _row::insert(E.cy, "", 0);
  } else {
    erow *row = &E.row[E.cy];
    
    _row::insert(E.cy + 1, &row->chars[E.cx], row->size - E.cx);
    row = &E.row[E.cy];
    row->size = E.cx;
    row->chars[row->size] = '\0';
    _row::update(row);
  }
  E.cy++;
  E.cx = 0;
}

void insertChar(int c) {
  if (E.cy == E.numrows) {
    _row::insert(E.numrows, "", 0);
  }
  _row::insertChar(&E.row[E.cy], E.cx, c);
  E.cx++;
}

void scroll() {
  E.rx = 0;
  if (E.cy < E.numrows) {
    _row::_CxToRx(&E.row[E.cy], E.cx);
  }

  if (E.cy < E.rowoff) {
    E.rowoff = E.cy;
  }
  if (E.cy >= E.rowoff + E.screenrows) {
    E.rowoff = E.cy - E.screenrows + 1;
  }
  if (E.rx < E.coloff) {
    E.coloff = E.rx;
  }
  if (E.rx >= E.coloff + E.screencols) {
    E.coloff = E.rx - E.screencols + 1;
  }
}

void drawRows(struct abuf ab) {
  for (int y = 0; y < E.screenrows; y++) {
    int filerow = y + E.rowoff;
    if (filerow >= E.numrows) {
      if (E.numrows == 0 && y == E.screenrows / 3) {
        char welcome[80];
        int welcomelen = snprintf(welcome, sizeof(welcome), "%s -- %s -- %s",
                                  NAME, VERSION, RELEASE);
        if (welcomelen > E.screencols)
          welcomelen = E.screencols;
        int padding = (E.screencols - welcomelen) / 2;
        if (padding) {
          buffer::append(ab, "~", 1);
          padding--;
        }
        while (padding--)
          buffer::append(ab, " ", 1);
        buffer::append(ab, welcome, welcomelen);
      } else {
        buffer::append(ab, "~", 1);
      }
    } else {
      int len = E.row[filerow].rsize - E.coloff;
      if (len < 0)
        len = 0;
      if (len > E.screencols)
        len = E.screencols;
      char *c = &E.row[filerow].render[E.coloff];
      unsigned char *hl = &E.row[filerow].hl[E.coloff];
      int current_color = -1;

      for (int j = 0; j < len; j++) {
        if (iscntrl(c[j])) {
          char sym = (c[j] <= 26) ? '@' + c[j] : '?';
          buffer::append(ab, "\x1b[7m", 4);
          buffer::append(ab, &sym, 1);
          buffer::append(ab, "\x1b[m", 3);
          // if (current_color != -1) {
          //   char buf[16];
          //   int clen = snprintf(buf, sizeof(buf), "\x1b[%dm", current_color);
          //   buffer::append(ab, buf, clen);
          // }
        }
        // else if (hl[j] == HL_NORMAL) {
        //   if (current_color != -1) {
        //     buffer::append(ab, "\x1b[39m", 5);
        //     current_color = -1;
        //   }
        //   buffer::append(ab, &c[j], 1);
        // } else {
        //   int color = editorSyntaxToColor(hl[j]);
        //   if (color != current_color) {
        //     current_color = color;
        //     char buf[16];
        //     int clen = snprintf(buf, sizeof(buf), "\x1b[%dm", color);
        //     buffer::append(ab, buf, clen);
        //   }
        //   buffer::append(ab, &c[j], 1);
        // }
      }
      buffer::append(ab, "\x1b[39m", 5);
    }

    buffer::append(ab, "\x1b[K", 3);
    buffer::append(ab, "\r\n", 2);
  }
}

void drawStatusBar(struct abuf ab) {
  buffer::append(ab, "\x1b[7m", 4);
  char status[80], rstatus[80];
  int len = snprintf(status, sizeof(status), "%.20s - %d lines %s",
                     E.filename ? E.filename : "[No Name]", E.numrows,
                     E.dirty ? "(modified)" : "");
  int rlen = snprintf(rstatus, sizeof(rstatus), "%s | %d/%d", "no ft", E.cy + 1,
                      E.numrows);
  if (len > E.screencols)
    len = E.screencols;
  buffer::append(ab, status, len);
  while (len < E.screencols) {
    if (E.screencols - len == rlen) {
      buffer::append(ab, rstatus, rlen);
      break;
    } else {
      buffer::append(ab, " ", 1);
      len++;
    }
  }
  buffer::append(ab, "\x1b[m", 3);
  buffer::append(ab, "\r\n", 2);
}

void drawMessageBar(struct abuf ab) {
  buffer::append(ab, "\x1b[K", 3);
  int msglen = strlen(E.statusmsg);
  if (msglen > E.screencols)
    msglen = E.screencols;
  if (msglen && time(NULL) - E.statusmsg_time < 5)
    buffer::append(ab, E.statusmsg, msglen);
}

void refreshScreen() {
  scroll();

  struct abuf ab = ABUF_INIT;

  buffer::append(ab, "\x1b[?25l", 6);
  buffer::append(ab, "\x1b[H", 3);

  drawRows(ab);
  drawStatusBar(ab);
  drawMessageBar(ab);

  char buf[32];
  snprintf(buf, sizeof(buf), "\x1b[%d;%dH", (E.cy - E.rowoff) + 1,
           (E.rx - E.coloff) + 1);
  buffer::append(ab, buf, strlen(buf));

  buffer::append(ab, "\x1b[?25h", 6);

  // write(STDOUT_FILENO, ab.b, ab.len);
  std::cout.write(ab.b.c_str(), ab.len);
}

//
void setStatusMessage(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vsnprintf(E.statusmsg, sizeof(E.statusmsg), fmt, ap);
  va_end(ap);
  E.statusmsg_time = time(NULL);
}
} // namespace output
