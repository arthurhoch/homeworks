#include "main.h"

int
main(int argc, char **argv)
{
	file2mem();
	
	struct problem **problems = &problem_first;

	printf("%s", (*problems)->data->problem);

	while(*problems)
	{
		struct data *data = (*problems)->data;
		//printf("%s\n", data->problem);

		struct num *num = data->num;

		while(num)
		{	
			printf("|%d|-", num->num);
			num = num->next;
		}

		problems = &(*problems)->next;	
	}

	return 0;
}
