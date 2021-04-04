#ifndef STACK_H
#define STACK_H

#include<stdbool.h>

#include"vector.h"

typedef struct Stack {
	Vector *vec;
	bool filled; /* Micro Optimization */
} Stack;

Stack *stack_init();
void stack_deinit(Stack *);
void *stack_top(Stack *);
bool stack_empty(Stack *);
void stack_push(Stack *, void *);
void stack_pop(Stack *);

#endif /* STACK_H */