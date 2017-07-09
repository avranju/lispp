#include "stddefs.h"
#include "pointer_array.h"
#include "node.h"
#include "string_buffer.h"
#include "lexer.h"
#include "parser.h"

void indent(int level);
void print_node(Node* node, int depth);

int main(int argc, char *argv[])
{
	char *code = "(sum (gen-multiples (gen-series 1000) 3 5))";
	Lexer *lexer;
	Node *root;

	//
	// if a lisp fragment has been passed in command line
	// then use that
	//
	if(argc > 1)
		code = argv[1];

	//
	// build parse tree
	//
	lexer = lexer_alloc(code);
	root = parser_parse(lexer);

	//
	// print tree
	//
	printf("\nLisp Code: %s\n\nParse Tree: \n", code);
	print_node(root, 1);

	//
	// free parse tree and lexer
	//
	node_free(root);
	lexer_free(lexer);

	return 0;
}

void indent(int level)
{
	int i;
	for(i = 0 ; i < level ; ++i)
		printf("   ");
}

void print_node(Node* node, int depth)
{
	int i;

	indent(depth);
	switch(node->type)
	{
	case List:
		printf("<list>\n");
		for(i = 0 ; i < node->list->length ; ++i)
			print_node(node->list->elements[i], depth + 1);
		break;

	case Symbol:
		printf("%s\n", node->symbol);
		break;
	}
}
