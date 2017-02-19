#ifndef LINE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct line_t {
	char str[BUFSIZ];

	// linked list line structure
	struct line_t *prev;
	struct line_t *next;
} line_t;

#endif