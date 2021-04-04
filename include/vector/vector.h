#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector {
	void **arr;
	int cap, size;
} Vector;

Vector *vector_init(int);
void vector_deinit(Vector *);
void vector_pushBack(Vector *, void *);
int vector_size(Vector *);
int vector_cap(Vector *);
void *vector_at(Vector *, int);

#endif /* VECTOR_H */