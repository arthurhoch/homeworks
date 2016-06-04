#ifndef FILES_H
#define FILES_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFLEN 10

struct num {
	int num;
	struct num *next;
};

struct data {
	char *problem;
	int weight;
	int num_sample;
	int num_pkg;
	struct num *num;
	struct data *next;
};

struct problem {
	struct data *data;
	struct problem *next;
};

struct data *data_first;
struct num	*num_first;
struct problem *problem_first;

void
add_data(struct data *element);

void
add_num(struct num *element);

void
add_problem(struct problem *element);

char *
file2char(FILE **filefb, char lastchar);

int
file2int(FILE **filefb, char lastchar);

struct problem *
file2mem();

#endif /* FILES_H */
