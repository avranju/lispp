#pragma once

#define STRING_BUFFER_BLOCK_LEN 128				// size of string buffer block

typedef struct _tagStringBuffer
{
	char *buffer;
	int length;
	int bufferLength;

} StringBuffer;

StringBuffer *sb_alloc(char *str);				// allocate string buffer object
void sb_free(StringBuffer *sb);					// free string buffer
void sb_append(StringBuffer *sb, char *str);	// append another string to buffer
void sb_appendc(StringBuffer *sb, char ch);		// append a character to buffer
