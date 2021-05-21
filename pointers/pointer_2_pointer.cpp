#include <stdio.h>

void tutorial_pointer_2_pointer() {
	printf("\nPointer to Pointer\n");

	int x = 5;
	int *p ;

	p = &x;

	printf("Value of x is %d\n", *p);
	printf("Address of x: %d\n", &x);
	printf("Address of p: %d\n", &p);
	printf("Value   of p: %d\n", p);


	int **pp;	// a pointer to point at a pointer
	pp = &p;	// store address of a pointer
	printf("Value of x is %d\n", *(*pp));
	printf("Address of double: %d\n", &pp);
	printf("Address of single: %d\n", pp);

	int ***tripple;
	tripple = &pp;
	printf("Value of x is %d\n", ***tripple);
	printf("Address of tripple: %d\n", &tripple);
	printf("Address of double: %d\n", tripple);
	***tripple = 10;
	printf("Value of x is %d\n", ***tripple);

	// tripple -> pp -> p -> x
}
