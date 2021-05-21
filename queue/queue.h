/*
 * queue.h
 *
 *  Created on: 21.05.2021
 *      Author: k3nny
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

#include "single_linked_list.h"

// struct queue
struct Queue {
	int length;
	struct Node* list;
};

// create new
struct Queue* create_queue(){
	struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
	queue->length = 0;
	queue->list = NULL;
	return queue;
}

/*
 * Enqueue at start
 */
void enqueue(struct Queue* queue, int data){
	insert_at_start(&queue->list, data);
	queue->length += 1;
}

/*
 * Dequeue at end
 */
int dequeue(struct Queue* queue) {
	int data = 0;
	if (queue->length > 0){
		queue->length -= 1;
		data = delete_elemtent(&queue->list, queue->length);

	}
	return data;
}


/*
 * Show contents
 */
void queue_show(struct Queue* queue){
	print_list(queue->list);
}

// destroy



#endif /* QUEUE_H_ */
