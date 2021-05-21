#include<stdio.h>

/*
 * Array can be given as int A[] or int* A
 * we can not calculate the size of the array inside the function!
 */
int sum_of_elements(int* A, int size){
	int i = 0, sum = 0;

	for (i = 0; i < size; i++){
		sum += A[i];
	}
	return sum;
}


void tutorial_arrays(){

	printf("\nArrays as function arguments\n");

	int A[] = {1,2,3,4,5};
	int size = sizeof(A) / sizeof(int);
	int sum = sum_of_elements(A, size);

	printf("sum of Array is: %d", sum);

}
