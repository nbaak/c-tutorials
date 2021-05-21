#include <stdio.h>


void tutorial_intro() {

	printf("\nIntro\n");


	/*
	 * A Pointer is a Variable that stores a memory address
	 * int* p = .. or int *p = ..: describes a pointer variable
	 * .. = &variable : returns the memory address of variable
	 * ...*p :  returns the value of a pouinter addresses destination
	 * *p = value : setzs the destination of p to value
	 */

	int a;
	int *p;		// pointer variable

	p = &a;		// store adress of a in p
	*p = 5;		// set pointer destination to 5

	printf("Adress of Pointer: %d\n", p);
	printf("Value of Pointer:  %d\n", &p);
	printf("Value of Destination:  %d\n", *p);
	printf("Value:  %d\n", a);
}
