#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

int main(void){

	struct Matrix* matrix = create_matrix(3, 3);
	int x,y;
	int count = 0;

	for (x = 0; x < 3; x++){
		for (y = 0; y < 3; y++){
			matrix_set_value(matrix, x, y, count);
			count++;
		}
	}


	matrix_print(matrix);

	free(matrix);
	return 0;
}
