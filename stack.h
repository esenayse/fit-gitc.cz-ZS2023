#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

struct stack_ctx {
	int *data;
	int stack_size;
	int pointer;
};

struct stack_ctx *stack_init(int initial_stack_size);
void stack_destroy(struct stack_ctx *ctx);
void stack_push(struct stack_ctx *ctx, int num);
int stack_pop(struct stack_ctx *ctx);
bool stack_is_empty(struct stack_ctx *ctx);

#endif //STACK_H
