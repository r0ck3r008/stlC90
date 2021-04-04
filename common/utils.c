#include<stdio.h>
#include<unistd.h>

#include<commons/utils.h>

void
nullExit(void *ptr)
{
	if(ptr == NULL) {
		fprintf(stderr, "[-]Out of memory!\n");
		_exit(1);
	}
}