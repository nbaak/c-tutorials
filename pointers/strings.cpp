#include <stdio.h>
#include <string.h>
/*
 * Arrays of Chars and Strigns
 */

#define EOS '\0'

void print(char* c) {
	while (*c != EOS){
		printf("%c", *c++);	// iterate through array by increasing the pointer address
	}
	printf("\n");
}


void tutorial_strings(){

	printf("\nArray of Chars\n");

	char c1[20];
	c1[0] = 'T';
	c1[1] = 'e';
	c1[2] = 's';
	c1[3] = 't';
	c1[4] =  '\0';	// needs to be terminated this way :/

	int len = strlen(c1);
	printf("length of string (\"%s\"): %d\n", c1, len);


	char c2[20] = "Meow!"; // defines a string
	printf("%s\n", c2);
	print(c1);


 	char *word = "Word!";	// string will be stored as constant on compile time
	print(word);

}
