/*
 * @file: queue_test.c
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "queue.h"

void print_len(struct Queue *q)
{
	printf("%d\n", queue_get_length(q));
}

int main(int argc, char **argv)
{
	struct Queue *strings = queue_new();

	queue_push_tail(strings, strdup("hello"));
	print_len(strings);
	queue_push_tail(strings, strdup("world"));
	print_len(strings);
	queue_push_tail(strings, strdup("in"));
	print_len(strings);
	queue_push_tail(strings, strdup("C"));
	print_len(strings);

	char *str = queue_pop_head(strings);
	printf("%s\n", str);
	free(str);

	print_len(strings);
	str = queue_pop_head(strings);
	printf("%s\n", str);
	free(str);

	queue_destroy(strings, free);

//	print_len(strings);
//	str = queue_pop_head(strings);
//	printf("%s\n", str);
//	free(str);
//
//	print_len(strings);
//	str = queue_pop_head(strings);
//	printf("%s\n", str);
//	free(str);
//
//	print_len(strings);
//	str = queue_pop_head(strings);
//	if (str) {
//		printf("%s\n", str);
//		free(str);
//	}
//	print_len(strings);

	return 0;
}
