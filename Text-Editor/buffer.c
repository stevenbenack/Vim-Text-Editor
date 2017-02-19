#include "buffer.h"

/**
* Initalizes a buffer
* @param  name file name to initalize the buffer with (can be null)
* @return      pointer to the initalized buffer
*/
buffer_t* buffer_create(const char * name) {
	buffer_t* buf = calloc(1, sizeof(buffer_t)); 
	if (name) {
		buf->name = strdup(name); //duplicate string
	}
	buffer_read(buf, name);
	return buf;
}