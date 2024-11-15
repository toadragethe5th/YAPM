#include <stdio.h>
#include <stdint.h>

#include "llist.h"

/*
	I am making this explicitly to store dependencies and packages included.

*/
struct node* makenode(char* data)
{
	struct node* node = (struct node*) malloc(sizeof(struct node)); /* This memory is freed after writing to the YPF file */
	node->data=data;
	node->next=NULL;
	return node;
}

void append(struct node* head, char* data)
{
	next = node->next;

	while (next != NULL) {
		next = node->next;
	}

	node->next = makenode(data);
}

void remove(struct node* head)
{
	struct node* tmp;

	while (head != NULL) {
		tmp = head;
		head = head->next;
	}

	free(tmp);
}

/* 
	This code is here thanks
	to the geniuses on stack
	overflow and the people 
	who wrote pacman.
*/
void free_list(struct node* head)
{
	struct node* tmp;

	while (head != NULL) {
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void print_list(struct node* head)
{
	struct node* tmp;

	while (head != NULL) {
		tmp = head;
		head = head->next;
		printf("%s ");
	}
}

