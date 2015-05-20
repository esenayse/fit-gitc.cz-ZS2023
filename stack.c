#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>

static void stack_realloc(struct stack_ctx *ctx)
{
	ctx->stack_size = 2 * ctx->stack_size;
	ctx->data = (int *) realloc(ctx->data, ctx->stack_size * sizeof(int));
}

struct stack_ctx *stack_init(int initial_stack_size)
{
	struct stack_ctx *ctx = (struct stack_ctx *) malloc(sizeof(struct stack_ctx));

	ctx->stack_size = initial_stack_size;
	ctx->pointer = 0;
	ctx->data = (int *) malloc(initial_stack_size * sizeof(int));

	return ctx;
}

void stack_destroy(struct stack_ctx *ctx)
{
	free(ctx->data);
	free(ctx);
}

void stack_push(struct stack_ctx *ctx, int num)
{
	if (ctx->pointer == ctx->stack_size) {
		stack_realloc(ctx);
	}

	ctx->data[ctx->pointer++] = num;
}

int stack_pop(struct stack_ctx *ctx)
{
	return ctx->data[--ctx->pointer];
}

bool stack_is_empty(struct stack_ctx *ctx)
{
	if (ctx->pointer == 0) {
		return true;
	} else {
		return false;
	}
}
