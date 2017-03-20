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

/*
* line_concat(): Concatinates the given line with the provided string
*
* return: void
*
* line_t* line	Line to concatinate to
* const char* str	String to append/concatinate to the line
* size_t length    Length of provided string
*/
void line_concat(line_t * line, const char * str, size_t length)
{
	strncat(line->str, str, length);
}

/*
* line_insert(): Inserts a character at the provided position in to the
*  given line
*
* return: void
*
* line_t* line    Line to insert a character in
* char chr		Character to insert into the line
* size_t idx	Index of the line to insert the character into
*/
void line_insert(line_t * line, char chr, size_t idx)
{
	//insert line to middle of string
	if (idx < strlen(line->str)) {
		char* split = line->str + idx;
		//move memory
		memmove(split +1, split, strlen(split));
	}
	line->str[idx] = chr; 
}

/*
* line_erase(): Erases a character at the provided position in to the
*  given line
*
* return: void
*
* line_t* line		Line to erase a character in
* size_t idx		Index of the character to erase
*/
void line_delete(line_t * line, size_t idx)
{
	//move the string to write over to delete
	if (idx < strlen(line->str)) {
		char* split = line->str + idx;
		memmove(split, split +1, strlen(split));
	}
}
