#pragma once
#include <termios.h>
#include <cstddef>

class winRow {
public:
	int idx;
};

class AppConfig {
public:
	int cx = 0, cy = 0;
	int rx = 0;
	int rowoff = 0;
	int coloff = 0;
	int numrows = 0;
	winRow *winrow = NULL;
	int screenrows;
	int screencols;
	struct termios orig_termios;

	AppConfig(int scrnrows, int scrncols) {
		cy = 0;
		cx = 0;
		rx = 0;
		rowoff = 0;
		coloff = 0;
		numrows = 0;
		// row = 
	}
};