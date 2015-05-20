#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stack.h"

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	int cnt = 1000000;
	srand(time(NULL));
	struct stack_ctx *stack = stack_init(2);

	while (cnt--) {
		stack_push(stack, rand() % 1000);
	}

	int num;
	while (!stack_is_empty(stack)) {
		num = stack_pop(stack);

		printf("On the stack was: %d\n", num);
	}

	stack_destroy(stack);

	return 0;
}
