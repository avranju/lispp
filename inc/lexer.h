#ifndef LEXER_H
#define LEXER_H

typedef struct _tagLexer
{
	char *code;
	int current;
	char *delims;

} Lexer;

Lexer *lexer_alloc(char *code);								// construct a lexer object
void lexer_free(Lexer *lexer);								// free lexer
int lexer_is_delim(Lexer *lexer, char ch);					// check if the given character is a delimiter
StringBuffer *lexer_internal_next_token(Lexer *lexer);		// private function to parse the next token from stream
StringBuffer *lexer_next_token(Lexer *lexer);				// fetch next token or NULL if end of stream
int token_is_white_space(StringBuffer *token);				// check if token is white-space

#endif // !LEXER_H