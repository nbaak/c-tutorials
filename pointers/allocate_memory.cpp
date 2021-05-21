#include <stdio.h>
#include <stdlib.h>


void tutorial_allocate_memory(){

	printf("\nAllocate Memory\n");

	int a;	// Variable on stack
	int *p;

	// Allocate Memory on Heap
	p = (int*) malloc(sizeof(int));		// malloc returns pointer to fresh memor space
	*p = 10;
	printf("Variable *p=%d (%d)\n", *p, p);
	free(p); 	// if you alloc space, you have to free it!


	p = (int*) malloc(sizeof(int));		// Allocate Memory on Heap
	*p = 20;
	printf("Variable *p=%d (%d)\n", *p, p);
	free(p);

	int array_len = 10;
	p = (int*) calloc(array_len, sizeof(int));		// Allocate Memory on Heap and initializes as 0
	printf("Variable *p=%d (%d)\n", *p, p);

	for (int i = 0; i<array_len; i++){
		p[i] = i;
		printf("%d ", p[i]);
	}


	free(p);



}
