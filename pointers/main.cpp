/*
 * A small program for my self to play with c
 */

#include <stdio.h>
#include <stdlib.h>

void tutorial_intro();
void tutorial_arguments();
void tutorial_arrays();
void tutorial_strings();
void tutorial_pointer_2_pointer();
void tutorial_multi_dim_array();
void tutorial_allocate_memory();

int main (void) {

	printf("CPP Tutorials for pointers\n");

	tutorial_intro();
	tutorial_arguments();
	tutorial_arrays();
	tutorial_pointer_2_pointer();
	tutorial_strings();
	tutorial_multi_dim_array();
	tutorial_allocate_memory();

	return 0;
}
