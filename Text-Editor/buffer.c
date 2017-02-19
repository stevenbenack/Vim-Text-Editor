#include "buffer.h"

/**
* Construct a buffer
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

/**
* Destroys a buffer
* @param buf buffer to deinit
*/
void buffer_free(buffer_t * buf) {
	if(!buf) return;

	buffer_clear(buf);

	buf->prev = NULL;
	buf->next = NULL;
	free(buf->name);
	free(buf); 
}

/**
* Reads the contents of a file or the buffer name into a buffer
* @param  buf  buffer to read into
* @param  name name of the file (can be null)
* @return 0 if success, 2 if file did not exist
*/
int buffer_read(buffer_t * buf, const char * name) {
	//reset the buffer before reading a new buffer
	buffer_clear(name); 
	FILE *fp; 

	//check if this is a file or a buffer
	if(name) fp = fopen(name, "r"); 
	else fp = fopen(buf->name, "r"); 

	if (fp) {
		char in[BUFSIZ]; 

		//read line by line from file
		while (fgets(in, BUFSIZ, fp) != NULL) {
			line_t* l = line_create(in, strlen(in) -1);
			buffer_append(buf, 1); 
		}
	}
}