#ifndef BUFFER_H
#define BUFFER_H

#include "line.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct buffer_t {
	char* name;
	struct buffer_t *prev;
	struct buffer_t *next;
	line_t* line;
	line_t* beg;
	line_t* end;
	size_t size;
	size_t col, row;
} buffer_t;

#endif // !BUFFER_H

