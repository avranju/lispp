#pragma once

Node *parser_parse(Lexer *lexer);			// parse lisp code and return root node
Node *parser_parse_list(Lexer *lexer);		// parse a lisp list
