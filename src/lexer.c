#include "stddefs.h"
#include "pointer_array.h"
#include "node.h"
#include "string_buffer.h"
#include "lexer.h"

Lexer *lexer_alloc(char *code)
{
	Lexer *lexer = (Lexer *)malloc(sizeof(Lexer));
	lexer->code = strdup(code);
	lexer->current = 0;
	lexer->delims = strdup("( )");

	return lexer;
}

void lexer_free(Lexer *lexer)
{
	if(lexer)
	{
		if(lexer->code)
			free(lexer->code);
		if(lexer->delims)
			free(lexer->delims);
		free(lexer);
	}
}

int lexer_is_delim(Lexer *lexer, char ch)
{
	int len, i;

	if(!lexer || !lexer->delims)
		return 0;

	len = strlen(lexer->delims);
	for(i = 0 ; i < len ; ++i)
		if(lexer->delims[i] == ch)
			return 1;

	return 0;
}

StringBuffer *lexer_internal_next_token(Lexer *lexer)
{
	int				code_len;
	StringBuffer	*token;
	char			ch;

	if(!lexer)
		return NULL;

	//
	// if we have reached end of code then return NULL
	//
	code_len = strlen(lexer->code);
	if(lexer->current >= code_len)
		return NULL;

	token = sb_alloc("");
	for(; lexer->current < code_len ; ++(lexer->current))
	{
		ch = lexer->code[lexer->current];
		if(lexer_is_delim(lexer, ch))
		{
			if(token->length == 0)
			{
				sb_appendc(token, ch);
				++(lexer->current);
			}

			break;
		}

		sb_appendc(token, ch);
	}

	return token;
}

int token_is_white_space(StringBuffer *token)
{
	int i;
	if(!token || !token->buffer || token->length == 0)
		return 1;

	for(i = 0 ; i < token->length ; ++i)
		if(token->buffer[i] != ' ' && token->buffer[i] != '\t')
			return 0;

	return 1;
}

StringBuffer *lexer_next_token(Lexer *lexer)
{
	StringBuffer *token = NULL;

	if(!lexer)
		return NULL;

	//
	// skip all white-space only tokens
	//
	while( ( ( token = lexer_internal_next_token(lexer) ) != NULL ) &&
		   ( token_is_white_space(token) ) )
		sb_free(token);

	return token;
}
