// Stacks

#include <stdio.h>
#include <stdlib.h>

//#include "array_stack.h"
#include "list_stack.h"

int main (){
	printf("\nStacks\n");
	struct Stack *stack = create_stack();

	push(stack, 42);
	push(stack, 44);


	int i;
	for (i = 0; i<3; i++){
		push(stack, i);
	}

	push(stack, 255);
	push(stack, 565);
	push(stack, 535);

	push(stack, 5335);
	push(stack, 5995);
	push(stack, 155);
	push(stack, 255);
	push(stack, 565);
	push(stack, 535);
	push(stack, 5335);
	push(stack, 5995);
	push(stack, 155);
	push(stack, 255);
	push(stack, 565);
	push(stack, 535);
	push(stack, 5335);
	push(stack, 5995);
	push(stack, 155);


	printf("top: %d\n", top(stack));

	int item = 0;
	do {
		printf("pop item: %d - %d\n", pop(stack), stack->size);
	}while(stack->size > 0);

	printf("pop item: %d - %d\n", pop(stack), stack->size);
	/* END */
	return 0;
}
