#include<stdio.h>
#include<stdlib.h>

#include<commons/utils.h>
#include<vector/vector.h>

/* Private */
Vector *
vector_grow(Vector *vec)
{
	Vector *new_vec = vector_init(vec->size * 2);
	for(int i = 0; i < vec->size; i++)
		new_vec->arr[i] = vec->arr[i];

	vector_deinit(vec);
	return new_vec;
}

/* Public */
Vector *
vector_init(int size)
{
	Vector *vec = (Vector *)calloc(sizeof(Vector), 1);
	nullExit(vec);

	vec->arr = calloc(sizeof(void *), size);
	nullExit(vec->arr);

	vec->cap = size;

	return vec;
}

void
vector_deinit(Vector *vec)
{
	free(vec->arr);
	free(vec);
}

void
vector_pushBack(Vector *vec, void *memb)
{
	int size = vec->size;
	if(size == vec->cap)
		vec = vector_grow(vec);

	vec->arr[size] = memb;
	(vec->size)++;
}

int
vector_size(Vector *vec)
{
	return (vec->size);
}

int
vector_cap(Vector *vec)
{
	return (vec->cap);
}

void *
vector_at(Vector *vec, int pos)
{
	if(pos >= vec->size || pos < 0)
		return NULL;

	return (vec->arr[pos]);
}