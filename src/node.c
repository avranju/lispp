#include "stddefs.h"
#include "pointer_array.h"
#include "node.h"

Node *node_alloc(NodeType type, void *content)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->type = type;
	switch(node->type)
	{
	case List:
		node->list = (PointerArray *)content;
		break;

	case Symbol:
		node->symbol = strdup((char *)content);
		break;
	}

	return node;
}

void node_free(Node *node)
{
	int i;
	if(node)
	{
		//
		// free symbol buffer if its a symbol
		//
		if(node->type == Symbol && node->symbol)
			free(node->symbol);

		//
		// free all node elements in the list
		//
		if(node->type == List && node->list)
		{
			for(i = 0 ; i < node->list->length ; ++i)
				node_free(node->list->elements[i]);

			pa_free(node->list);
		}

		free(node);
	}
}

Node *node_make_symbol(char *symbol)
{
	return node_alloc(Symbol, symbol);
}

Node *node_make_list(PointerArray *list)
{
	return node_alloc(List, list);
}
