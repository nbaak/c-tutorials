#ifndef MATRIX_H_
#define MATRIX_H_

struct Matrix {
	int dim_x;
	int dim_y;

	int* field;

};

struct Matrix* create_matrix(int dim_x, int dim_y){
	struct Matrix* matrix = (struct Matrix*) malloc(sizeof(struct Matrix));
	matrix->dim_x = dim_x;
	matrix->dim_y = dim_y;

	int **field;
	field = (int**) malloc(dim_y * sizeof(int*));
	for(int i = 0; i < dim_x; i++){
		field[i] = (int*) calloc(dim_x, sizeof(int));
	}

	matrix->field = field;

	return matrix;
}

void matrix_set_value(struct Matrix *matrix, int p_x, int p_y, int value){
	if (p_x > matrix->dim_x || p_x < 0) return;
	if (p_y > matrix->dim_y || p_y < 0) return;
	matrix->field[p_x * matrix->dim_y + p_y] = value;
}

void matrix_print(struct Matrix *matrix){
	size_t i,j;
	printf("\n");
	for(i=0;i<matrix->dim_x;i++){
		for(j=0;j<matrix->dim_x;j++){
			printf("%4d ", matrix->field[i * matrix->dim_x + j]);
		}
		printf("\n");
	}
}



#endif /* MATRIX_H_ */
