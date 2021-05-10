
#ifndef ARRAY_BASED_STACK
#define ARRAY_BASED_STACK


struct Stack {
	int top;
	int max_size;
	int size;
	int *list;
	int dynamic_array;
};

struct Stack *create_stack(int size){
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->size = 0;
	stack->max_size = size;
	stack->dynamic_array = 0;
	stack->list = (int*) malloc(size*sizeof(int));
	return stack;
}

void push(struct Stack *stack, int value){
	if (stack->dynamic_array == 1)
		stack->list = (int*) malloc(sizeof(int));	// problem when array becomes big oder time

	stack->top ++;
	stack->list[stack->top] = value;
	stack->size += 1;
}

int top(const struct Stack *stack){
	if (stack->top == -1) return -1;
	return stack->list[stack->top];
}

int pop(struct Stack *stack){
	if (stack->top == -1){
		printf("Error: No element on Stack!\n");
		return -1;
	}
	stack->top--;
	stack->size -= 1;
	return stack->list[stack->top];
}



#endif
