/*
 * Linked List in C
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>

#include "double_linked_list.h"


int main (){
	printf ("Linked List\n");
	struct Node* list;
    list = NULL;		// list is empty at the beginning

    // adding at the start
    insert_at_start(&list,	5);
    insert_at_start(&list,	4);
    insert_at_start(&list,	1);

    // adding at the end
    insert_at_end(list, 4);
    insert_at_end(list, 8);
    insert_at_end(list, 9);

    insert_at_start(&list,	0);


    insert_at_end(list, 42);
    insert_at_end(list, 43);
    insert_at_end(list, 44);


    insert_at_position(&list, 666, 3);
    insert_at_position(&list, 777, 3);
    insert_at_position(&list, 888, 7);

    printf("List of %d elements\n", get_list_length(list));
    print_list(list);

    delete_elemtent(&list, 4);
	delete_elemtent(&list, 1);
	delete_elemtent(&list, 0);
    printf("\nList of %d elements\n", get_list_length(list));
    print_list(list);

    printf("\nReverse!\n");
    reverse_list(&list);
    print_list(list);

    print_list_recursive(list);
    reverse_list_recursive(&list, list);
    print_list_recursive(list);

    printf("\ncount things\n");
    int c = 0;
    get_list_length_recursive(list, &c);
    printf("num: %d\n", c);

	/* */

    //free (temp); 	// ist you alloc, you have to free!
	return 0;
}
