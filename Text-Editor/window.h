#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

//define window
typedef struct window_t {
	WINDOW*		win;			//from ncurses
	size_t		cols, rows;
	size_t		top, bottom; 
};

#endif // !window_h
