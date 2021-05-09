
#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST
#endif


#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};


struct Node* create_new_node(int value){
	struct Node* node = (struct Node*) malloc(sizeof(struct Node)); // in cpp : Node* temp = new Node();
	node->data = value;		// same as: (*temp).data = 2;
	node->next = NULL;		// same as: (*temp).link = NULL;
	node->prev = NULL;

	return node;
}


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
		/*
		if (index > 0)
			printf(" - prev: %d\n", ptr->prev->data);
		if (index < get_list_length(list))
			printf(" - next: %d\n", ptr->next->data);
		/* */
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
	struct Node* temp = create_new_node(value);

	if (*ptr_list != NULL) {
		temp->next = *ptr_list;
		temp->next->prev = temp;
	}

	*ptr_list = temp;

}

void insert_at_end(struct Node *list, int value){
	struct Node* temp = create_new_node(value);

	struct Node* ptr = list;
	while (ptr->next != NULL){
		ptr = ptr->next;
	}
	temp->prev = ptr;
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
	struct Node* new_node = create_new_node(value);

	if (position == 0){
		new_node->next = *ptr_list;
		*ptr_list = new_node;
		return;
	}

	struct Node* before = get_node_at_postition(*ptr_list, position-1);
	struct Node* after = get_node_at_postition(*ptr_list, position);

	before->next = new_node;
	new_node->prev = before;

	new_node->next = after;
	after->prev = new_node;
}

void delete_elemtent(struct Node **ptr_list, int position){
	struct Node* del = get_node_at_postition(*ptr_list, position);
	struct Node* before = get_node_at_postition(*ptr_list, position-1);
	struct Node* after  = get_node_at_postition(*ptr_list, position+1);

	if (position == 0){
		*ptr_list = after;
	}else{
		before->next = after;
		after->prev = before;
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
	next = NULL;

	while (current != NULL){
		next = current->next;
		current->next = prev;
		current->prev = next;

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

void delete_list_recursive(struct Node **list, struct Node *node){
	if (node->next == NULL){
		return;
	}
	reverse_list_recursive(list, node->next);
	free(node);
}
