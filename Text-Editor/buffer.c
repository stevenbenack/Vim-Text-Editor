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
	else {
		//if can't open file, open new buffer
		//TODO change options if can't open
		line_t* l = line_create(NULL, 0);
		buffer_append(buf, l);
		buf->line = l;
	}
	//file does not exist
	return 0;
}

/**
* Writes the contents of a buffer into a file
* @param  buf  buffer to write to a file
* @param  name name of the file to write (can be null)
* @return 0 if success, 2 if could not write
*/
int buffer_write(buffer_t * buf, const char * name)
{
	FILE *fp;

	//if the file name exists, write to file, 
	//else create new buf with said name
	if (name) fp = fopen(name, "w");
	else fp = fopen(buf->name, "w");

	if(fp){
		for(line_t* l = buf->beg; l != NULL; l = l->next)
			//write to file
			fprint(fp, "%s\n", l->str);

		fclose(fp);
		return 1;
	}
	return 0;
}

/**
* Appends a line to a buffer
* @param buf  Buffer to append to
* @param line Line to append
*/
void buffer_append(buffer_t * buf, line_t * line)
{
	//either append to buffer (linked list) 
	//or create new
	if (buf->end) {
		line->prev = buf->end;
		line->prev->next = line; 
		buf->end = line;
	}
	else {
		buf->beg = buf->end = line; 
	}
	buf->size++;
}

/**
* Prepend a line to a buffer
* @param buf  Buffer to prepend to
* @param line Line to prepend
*/
void buffer_prepend(buffer_t * buf, line_t * line)
{
	if (buf->beg) {
		line->next = buf->beg; 
		line->next->prev = line;
		buf->beg = line;
	}
	else {
		buf->beg = buf->end = line; 
	}
	buf->size++;
}

