#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "llist.h"

/*
	I am making this explicitly to store dependencies and packages included.

*/
node_t* makenode(char* data)
{
	node_t* node = (node_t*) malloc(sizeof(node_t)); /* This memory is freed after writing to the YPF file */
	node->data=data;
	node->next=NULL;
	return node;
}

void append(node_t* head, char* data)
{
	next = node->next;

	while (next != NULL) {
		next = node->next;
	}

	node->next = makenode(data);
}

void remove(node_t* head)
{
	node_t* tmp;

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
void free_list(node_t* head)
{
	node_t* tmp;

	while (head != NULL) {
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

char* print_list(node_t* head)
{
	node_t* tmp;
	char temp2[20]; /* I love clean naming conventions */
	char* listdata;

	while (head != NULL) {
		tmp = head;
		head = head->next;
		snprintf(temp2, sizeof(temp2), "%s ", tmp->data);
		strcat(listdata, temp2);
	}

	return listdata;
}
