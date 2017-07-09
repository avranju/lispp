#include "stddefs.h"
#include "string_buffer.h"

StringBuffer *sb_alloc(char *str)
{
	StringBuffer *sb = (StringBuffer *)malloc(sizeof(StringBuffer));
	sb->length = strlen(str);
	sb->bufferLength = max(STRING_BUFFER_BLOCK_LEN, sb->length);
	sb->buffer = malloc(sb->bufferLength * sizeof(char));
	strcpy(sb->buffer, str);

	return sb;
}

void sb_free(StringBuffer *sb)
{
	if(sb)
	{
		if(sb->buffer)
			free(sb->buffer);
		free(sb);
	}
}

void sb_append(StringBuffer *sb, char *str)
{
	int len;

	if(!sb || !str)
		return;

	len = strlen(str);

	//
	// if current length + length of new string will
	// exceed buffer length then allocate another block
	//
	if((sb->length + len) >= sb->bufferLength)
	{
		sb->bufferLength = max(sb->bufferLength + STRING_BUFFER_BLOCK_LEN, sb->length + len);
		sb->buffer = realloc(sb->buffer, sb->bufferLength);
	}

	sb->length += len;
	strcat(sb->buffer, str);
}

void sb_appendc(StringBuffer *sb, char ch)
{
	char str[2];

	str[0] = ch;
	str[1] = '\0';
	sb_append(sb, str);
}
