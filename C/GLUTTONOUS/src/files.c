#include "files.h"

void
add_data(struct data *element)
{
	element->next = data_first;
	data_first = element;
}

void
add_num(struct num *element)
{
	element->next = num_first;
	num_first = element;
}

void
add_problem(struct problem *element)
{
	element->next = problem_first;
	problem_first = element;
}

char *
file2char(FILE **filefb, char lastchar)
{
	char filechar = lastchar;
	char buffer[BUFFLEN];
	int position = 0;
	do
	{
		buffer[position] = filechar;
		filechar = fgetc(*filefb);
		position++;
	} while(filechar != '\n' && filechar != ' ' );
	buffer[position] = '\0';

	char *str = malloc((position--)*sizeof(char));
	if(buffer[0] ==  ' ')
		strcpy(str, &buffer[1]);
	else
		strcpy(str, &buffer[0]);
	return str;
}

int
file2int(FILE **filefb, char lastchar)
{
	int num;
	char filechar = lastchar;
	char buffer[BUFFLEN];
	int position = 0;
	do
	{
		if(filechar == ' ')
			filechar = fgetc(*filefb);

		buffer[position] = filechar;
		filechar = fgetc(*filefb);
		position++;
	} while(filechar != '\n' && filechar != ' ');

	buffer[position] = '\0';
	char *str = malloc((position--)*sizeof(char));
	
	if(buffer[0] ==  ' ')
		strcpy(str, &buffer[1]);
	else
		strcpy(str, &buffer[0]);

	num = atoi(str);
	free(str);
	return num;
}

struct problem *
file2mem()
{
	FILE *filefb;
	char filechar;
	bool meta = false;
	bool first = true;
	struct data *data;
	struct num	*num;
	char buffer[BUFFLEN];

	int metadata = 0;
	int position = 0;
	int sample, pkg;

	filefb = fopen("b1.txt", "r");

	while( filechar != EOF)
	{
		if(!meta)
		{
			filechar = fgetc(filefb);
			if(filechar != '\n')
			{
				buffer[position] = filechar;
				position++;
			}
			else
			{
				buffer[position] = '\0';
				num = malloc(sizeof(struct num));
				num->num = atoi(buffer);
				add_num(num);
				position = 0;
				bzero(buffer, BUFFLEN);
			}
		}
		if(filechar != EOF)
		{
			
			if(filechar == ' ' || meta == true)
			{
				metadata++;
				switch(metadata)
				{
					case 1:

						if(first)
						{
							data = malloc(sizeof(struct data));
							first = false;
						}
						else
						{
							data->num = num;
							struct problem *problem = malloc(sizeof(struct problem));
							problem->data = data;
							add_problem(problem);
							data = malloc(sizeof(struct data));
						}
						char *str = file2char(&filefb, filechar);
						data->problem = str;
						meta = true;
						break;
					case 2:
						fgetc(filefb);
						int weight = file2int(&filefb, filechar);
						data->weight = weight;
						break;
					case 3:
						sample = file2int(&filefb, filechar);
						data->num_sample = sample;
						break;
					case 4:
						pkg = file2int(&filefb, filechar); 
						data->num_pkg = pkg;
						meta = false;
						metadata = 0;
						break;
				}
			}
		}
	}
	fclose(filefb);

	data->num = num;
	struct problem *problem = malloc(sizeof(struct problem));
	problem->data = data;
	add_problem(problem);
	
	return 0;
}
