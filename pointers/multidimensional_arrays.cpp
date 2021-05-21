#include <stdio.h>
#include <stdlib.h>


void fill_3d(int A[][3][3], int max_x, int max_y, int max_z){
	int start = 0;
	for (int x = 0; x < max_x; x++){
		for (int y = 0; y < max_y; y++){
			for (int z = 0; z < max_z; z++){
				A[x][y][z] = start;
				start ++;
				//printf("%d ", start);
			}
		}
	}
}

// fill 2d array with values starting with 0
void fill_2d(int A[][3], int max_x, int max_y){
	int start = 0;
	for (int x = 0; x < max_x; x++){
		for (int y = 0; y < max_y; y++){
			A[x][y] = start;
			printf("%d ", start);
			start ++;
		}
		printf("\n");
	}
}


// not very sexy...
void get_pos(int *A){
	int x = 2;
	int *p = A;
	printf("int %i, %i\n", sizeof(int), x*sizeof(int));
	printf("%d, %d\n", *(A), A);
	printf("%d, %d\n", *(A + x), A+x*sizeof(int));

}

void analyze(int *A){
	printf("ANALYZING A!\n");
	printf("Address A: %d\n", A);
	printf("Value   A: %d\n", *(A));
	printf("Value   A: %d\n", *(A+1));
	printf("Value   A: %d\n", *(A+10));

}

void print_arr(int *arr, size_t s1, size_t s2){
	size_t i,j;
	printf("\n");
	for(i=0;i<s1;i++){
		for(j=0;j<s2;j++){
			printf("%4d ", arr[i * s2 + j]);
		}
		printf("\n");
	}
}

void set_value(int *arr, int size_x, int size_y, int p_x, int p_y, int value){
	arr[p_x * size_y + p_y] = value;
}

// g++ compiler does not like *(t)[3]
void test_2d(int t[][3]){
	printf("address 2d: %d\n", t);
	printf("value 2d: %d\n", t[1][1]);
	*(*(t+1)+1) = 3;
	printf("value 2d: %d\n", *(*(t+1)+1));
}


void tutorial_multi_dim_array() {

	printf("\nMultidimensional Arrays with Pointers\n");
	int MAX_X = 2, MAX_Y = 3;
	int B[2][3] = {{2,3,4},{4,5,8}};
    printf("Address of B: %d\n", B);
	//test_2d(B);

	int i = 0;
	int j = 0;

	/*
	for (i=0; i < MAX_X; i++){
		for (j=0; j < MAX_Y; j++){
			printf("field: B[%i][%i]\n", i,j);
			printf("Pointer: %d\n",*(*(B+i)+j));
			printf("Array:   %d\n", B[i][j]);
		}
	}
	*/


	printf("\nFancy Stuff\n");

	int max_x = 3, max_y = 3, max_z = 3;
	int A[3][3][3];
	int C[3][3];

	// fill
	for (int x = 0; x < max_x; x++){
		for (int y = 0; y < max_y; y++){
			for (int z = 0; z < max_z; z++){
				A[x][y][z] = 42;
			}
		}
	}
	//A = new_array(max_x, max_y, max_z, 5);

	fill_3d (A, max_x, max_y, max_z);

	printf("Address of A: %d\n", A);
	printf("Address of A: %d\n", &A);
	void *t = (void*) A;
	printf("T: %d\n", (int*) t);
	analyze((int*)t);

	printf("test: %d\n", A[2][2][2]);
	printf("test: %d\n", *(*(*(A+2)+2)+2));


	fill_2d (B, max_x, max_y);
	t = (void*)B;
	get_pos((int*)t);

	printf("2d arr\n");
	int T[3][3] = {{1,2,3},{22,33,44},{100,200,300}};
	set_value(T[0],3,3, 2,2, 1000);
	print_arr(T[0],3,3);

}
