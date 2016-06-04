#include "tree.h"

BTREE*
alloc_node(int weight, int value, char *name)
{
	BTREE *node;

	node = malloc(sizeof(BTREE));
	node->name = name;
	node->weight = weight;
	node->value = value;
	node->side = false;

	node->left = NULL;
	node->right = NULL;
	node->prev = NULL;

	return node;
}

BTREE*
create_tree()
{
	BTREE *start;

	start = alloc_node(0,0, "root");

	return start;
}

BTREE *
go_prev(BTREE *node)
{
	node = node->prev;
	return node;
}

void
print_node(BTREE *node)
{
	printf("Node { ");
	printf("Weight : %d, ", node->weight);
	printf("Value  : %d", node->value);
	printf(" }\n");
	return;
}

BTREE *
add_left(BTREE *node, char *name)
{
	node->left = alloc_node( (node->weight), (node->value), name );
	node->left->prev = node;
	return node->left;
}

BTREE *
add_right(BTREE *node, int weight, int value, char *name)
{
	node->right = alloc_node( (node->weight + weight), (node->value + value), name );
	node->right->prev = node;
	return  node->right;
}
