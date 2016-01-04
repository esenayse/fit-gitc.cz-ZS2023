#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stack.h"

#define TEST_SUM 1000000
#define TEST_CYCLES 10

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	srand(time(NULL));

	for (int i = 0; i < TEST_CYCLES; i++) {
		printf("Testing cycle %d\n", i);
		struct stack_ctx *stack = stack_init(4096);

		int num;
		int sum = 900;
		stack_push(stack, sum);

		while (sum < TEST_SUM && !stack_is_empty(stack)) {
			if ((rand() % 5) < 4) {
				num = rand() % 1000;
				stack_push(stack, num);
				sum += num;
				printf("Add %d\texpected sum is %d\n", num, sum);
			} else {
				num = stack_pop(stack);
				sum -= num;
				printf("Sub %d\texpected sum is %d\n", num, sum);
			}
		}

		while (!stack_is_empty(stack)) {
			num = stack_pop(stack);
			sum -= num;
			printf("Sub %d\texpected sum is %d\n", num, sum);
		}

		if (sum != 0) {
			fprintf(stderr, "Test failed!\n");
			return 1;
		}
		stack_destroy(stack);
	}

	// Make sure that there will be a lot of reallocs
	struct stack_ctx *stack = stack_init(1);
	int num;
	int sum = 0;

	while (sum < TEST_SUM) {
		num = rand() % 50;
		stack_push(stack, num);
		sum += num;
		printf("Add %d\texpected sum is %d\n", num, sum);
	}

	while (!stack_is_empty(stack)) {
		num = stack_pop(stack);
		sum -= num;
		printf("Sub %d\texpected sum is %d\n", num, sum);
	}

	if (sum != 0) {
		fprintf(stderr, "Test failed!\n");
		return 1;
	}

	stack_destroy(stack);

	return 0;
}
