#include "stddefs.h"
#include "pointer_array.h"
#include "node.h"
#include "string_buffer.h"
#include "lexer.h"
#include "parser.h"

Node *parser_parse_list(Lexer *lexer)
{
	StringBuffer *token;
	PointerArray *lst = pa_alloc();
	Node *root = NULL;

	while( ( ( token = lexer_next_token(lexer) ) != NULL ) &&
		   ( strcmp( token->buffer, ")" ) != 0 ) )
	{
		if(strcmp( token->buffer, "(" ) == 0)
			pa_push(lst, parser_parse_list(lexer));
		else
			pa_push(lst, node_make_symbol(token->buffer));

		sb_free(token);
	}

	if(token != NULL)
		sb_free(token);

	return node_make_list(lst);
}

Node *parser_parse(Lexer *lexer)
{
	//
	// first token MUST be "("
	//
	StringBuffer *token = lexer_next_token(lexer);
	if(strcmp( token->buffer, "(") != 0)
	{
		sb_free(token);
		return NULL;
	}
	sb_free(token);

	return parser_parse_list(lexer);
}
