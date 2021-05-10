/*
 * Siinge_Linked_List.h
 *
 *  Created on: 10.05.2021
 *      Author: k3nny
 */

#ifndef DEBUG_SINGE_LINKED_LIST_H_
#define DEBUG_SINGE_LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>

struct SLL_Node {
	int data;
	struct SLL_Node* next;
};

struct SLL_Node* sll_create_node(int data){
	struct SLL_Node* node = (struct SLL_Node*) malloc(sizeof(struct SLL_Node));
	node->data = data;
	node->next = NULL;
	return node;
}

void sll_insert_at_start(struct SLL_Node **list, int value){
	struct SLL_Node* node = sll_create_node(value);
	node->data = value;
	node->next = *list;
	*list = node;
}

void sll_delete_elemtent(struct SLL_Node **list){
	struct SLL_Node* del  = NULL;

	if (*list == NULL) return;
	del = *list;
	*list = (*list)->next;

	free(del);
}

#endif /* DEBUG_SINGE_LINKED_LIST_H_ */
