#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};


int get_list_length(struct Node *list){
	struct Node* ptr = list;
	int index = 0;

	while (ptr != NULL) {
		ptr = ptr->next;
		index += 1;
	}
	return index;
}

int get_list_length_recursive(struct Node *list, int *counter){
	if (list == NULL) return 0;
	*counter += 1;
	get_list_length_recursive(list->next, counter);
	return *counter;
}

void print_list(struct Node *list){
	struct Node* ptr = list;
	int index = 0;

	while (ptr != NULL) {
		printf("(%d.) %d\n", index, ptr->data);
		ptr = ptr->next;
		index += 1;
	}
}

/*
 * Recursive printing of List
 */
void print_list_recursive(struct Node *node){
	if (node != NULL){
		printf("%d ", node->data);
		print_list_recursive(node->next);
	} else {
		printf("\n");
		return;		// Exit
	}
}

void insert_at_start(struct Node **ptr_list, int value){
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node)); // in cpp : Node* temp = new Node();
	temp->data = value;		// same as: (*temp).data = 2;
	temp->next = NULL;		// same as: (*temp).link = NULL;

	if (*ptr_list != NULL) temp->next = *ptr_list;
	*ptr_list = temp;

}

void insert_at_end(struct Node *list, int value){
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = value;
	temp->next = NULL;

	struct Node* ptr = list;
	while (ptr->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = temp;
}

struct Node* get_node_at_postition(struct Node *list, int position){
	struct Node* ptr = list;
	int current_position = 0;
	while (ptr->next != NULL){

		if(current_position == position)
			break;

		ptr = ptr->next;
		current_position++;
	}
	return ptr;
}

void insert_at_position(struct Node **ptr_list, int value, int position){

	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = value;
	temp->next = NULL;

	if (position == 0){
		// put at first position
		temp->next = *ptr_list;
		*ptr_list = temp;
		return;
	}

	struct Node* before = get_node_at_postition(*ptr_list, position-1);
	struct Node* after = get_node_at_postition(*ptr_list, position);

	before->next = temp;
	temp->next = after;
}

void delete_elemtent(struct Node **ptr_list, int position){
	struct Node* del = get_node_at_postition(*ptr_list, position);
	struct Node* before = get_node_at_postition(*ptr_list, position-1);
	struct Node* after  = get_node_at_postition(*ptr_list, position+1);

	if (position == 0){
		*ptr_list = after;
	}else{
		before->next = after;
	}
	free(del);
}

/**
 * Iterative approach to reverse a list
 */
void reverse_list(struct Node **list){
	struct Node *current, *prev, *next;
	current = *list;
	prev = NULL;

	while (current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*list = prev;
}

void reverse_list_recursive(struct Node **list, struct Node *node){
	if (node->next == NULL){
		*list = node;
		return;
	}
	reverse_list_recursive(list, node->next);
	//struct Node* next = node->next;
	//next->next = node;
	node->next->next = node;
	node->next = NULL;
}

struct Node* copy_list(struct Node *list){
	struct Node *new_list = NULL;

	while (list != NULL){

		insert_at_end(new_list, list->data);
		list = list->next;

	}

	return new_list;
}

void delete_list(struct Node **list){
	;
}

#endif
