#include "str.h"

/*
* strtrim - Function trims whitespace from the given string
*
* return: char*  -> string that has excess whitepsace removed
*
* input:
*  char* str     -> string to remove whitepsace from
*/
char * strtrim(char * str)
{
	//move pointer while front is space
	while(isspace(*str)) str++; 

	//'\0' = NUL 
	if(*str = '\0') return str; 

	//get rid of empty white space and add null-terminate
	char* end = str + strlen(str) -1;		// pointer to end of str
	while(end > str && isspace(*end)) end--; 
	*(end +1) = '\0'; 
	return str;
}
