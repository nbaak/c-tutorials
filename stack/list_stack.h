/*
 * linked_list_stack.h
 *
 *  Created on: 10.05.2021
 *      Author: k3nny
 */

#ifndef LIST_STACK_H_
#define LIST_STACK_H_

#include <stdio.h>
#include <stdlib.h>

#include "Single_Linked_List.h"

struct Stack {
	int size;
	struct SLL_Node* list;
};


struct Stack* create_stack(){
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->size = 0;
	stack->list = NULL;
	return stack;
}



void push(struct Stack *stack, int data){
	sll_insert_at_start(&stack->list, data);
	stack->size += 1;
}

int pop(struct Stack *stack){
	if ((stack)->size > 0){
		int data = stack->list->data;
		stack->size -= 1;
		sll_delete_elemtent(&stack->list);
		return data;
	}

	printf("Stack is Empty\n");
	return 0;
}

int top(struct Stack *stack){
	if (stack->size >0)
		return stack->list->data;
	return 0;
}

#endif /* LIST_STACK_H_ */
