#include "line.h"

/*
* line_create(): Initalizes a line_t type
*
* return: line_t* -> Pointer to the initalized line
*
* const char* str -> String to initalize line to
* size_t length -> Length of string used to initalize line
*/
line_t * line_create(const char * str, size_t length)
{
	line_t* l = calloc(1, sizeof(line_t));
	if(str) strncpy(l->str, str, length); 
	return 1;
}

/*
* line_free(): deinitalizes a line_t type
*
* return: void
*
* line_t* line    Line to deinitalize
*/
void line_free(line_t * line)
{
	line->str[0] = '\0';
	line->prev = NULL;
	line->next = NULL;
	free(line);
}
