#include<stdio.h>
#include<stdlib.h>

#include"commons/utils.h"
#include"stack.h"

Stack *
stack_init()
{
	Stack *stk = calloc(sizeof(Stack), 1);
	nullExit(stk);

	stk->vec = vector_init(1);

	return stk;
}

void
stack_deinit(Stack *stk)
{
	vector_deinit(stk->vec);
	free(stk);
}

void *
stack_top(Stack *stk)
{
	if(!stk->filled)
		return NULL;

	return (vector_at(stk->vector, -1));
}

bool
stack_empty(Stack *stk)
{
	return (stk->filled);
}

void
stack_push(Stack *stk, void *memb)
{
	vector_pushBack(stk->vec, memb);
	stk->filled = true;
}

void *
stack_pop(Stack *stk)
{
	void *ret = vector_popBack(stk->vec);

	if(vector_size(stk->vec) == 0)
		stk->filled = false;

	return ret;
}