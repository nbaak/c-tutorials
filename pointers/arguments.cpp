#include <stdio.h>


/*
 * Function with call by reference argument
 */
void increment(int *a) {
	*a = *a + 1;
}

/*
 * Function with call by value
 * it will not affect the variable a outside the functions scope
 */
int increment2(int a) {
	return a + 1;
}

void tutorial_arguments() {
	printf("\nPointer as function arguments - call by reference\n");

	int variable = 10;
	printf("variable: %d\n", variable);
	increment(&variable);
	printf("variable: %d\n", variable);
	increment2(variable);
	printf("variable: %d\n", variable);

}
