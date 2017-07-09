#ifndef NODE_H

typedef enum _tagNodeType
{
	List,
	Symbol

} NodeType;

struct Node;

typedef struct _tagNode
{
	NodeType type;
	union
	{
		PointerArray *list;
		char *symbol;
	};

} Node;

Node *node_alloc(NodeType type, void *content);		// construct a node
void node_free(Node *node);							// free the node graph
Node *node_make_symbol(char *symbol);				// allocate a symbol node
Node *node_make_list(PointerArray *list);			// allocate a list node

#endif // !NODE_H
