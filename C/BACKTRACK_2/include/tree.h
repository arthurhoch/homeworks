#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BTREE{
	bool side;
	bool inbag;
	struct BTREE *prev;
	struct BTREE *left;
	struct BTREE *right;
	char *name;
	int weight;
	int value;
} BTREE;

BTREE*
alloc_node(int weight, int value, char *name);

BTREE*
create_tree();

BTREE*
go_prev(BTREE *node);

void
print_node(BTREE *node);

BTREE*
add_left(BTREE *node, char *name);

BTREE*
add_right(BTREE *node, int weight, int value, char *name);

#endif /* TREE_H */
