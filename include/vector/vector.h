#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector {
	void **arr;
} Vector;

Vector *vector_init(int);
void vector_deinit(Vector *);

#endif /* VECTOR_H */