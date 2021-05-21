#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main () {

	printf ("\nQUEUE\n\n");

	struct Queue *queue = create_queue();

	for (int i=0; i<10; i++){
		enqueue(queue, i);
	}


	queue_show(queue);


	for (int j=0; j<10; j++){
		printf("%i \n", dequeue(queue));
	}

	return 0;
}
