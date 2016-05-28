#include "main.h"

int
main(int argc, char **argv)
{
	int aw[] = {9, 13, 153, 50, 15, 68, 27, 39, 23, 52, 11, 32, 24, 48, 73, 42, 43, 22, 7, 18, 4, 30};
	int av[] = {150, 35, 200, 160, 60, 45, 60, 40, 30, 10, 70, 30, 15, 10, 40, 70, 75, 80, 20, 12, 50, 10};
	
	size_t len = (sizeof aw /sizeof(int));

	BTREE *tree = create_tree();

	array2tree(tree, aw, av, len);

	return 0;
}

void
array2tree(BTREE *tree, int aw[], int av[], size_t len)
{
	bool first = true;
	bool secund = true;
	int level = 0;
	int galhos = 0;
	BTREE *node = tree;

	BTREE *best_node = alloc_node(0, 0);

	while(node->side == false || first == true || secund == true)
	{
		first = false;
		if(level < len)
		{
			if(node->left == NULL)
			{
				node = add_left(node);
				level++;	
				galhos++;
			}
			else if(node->right == NULL)
			{
				node = add_right(node, aw[level], av[level]);
				level++;
				galhos++;
			}
			else if(node->prev != NULL)
			{
				node = go_prev(node);
				level--;
			}
		}
		else
		{
			node = go_prev(node);
			level--;
		}

		if(level == 0)
		{
			if(node->side == true)
				secund = false;
			node->side = true;
		}

		if(level == len)
		{
			if(node->weight <= 400 && node->value > best_node->value)
				best_node = node;
		}
	}
	printf("Best node: ");
	print_node(best_node);
	return;
}
