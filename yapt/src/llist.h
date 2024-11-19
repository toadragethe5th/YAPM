#ifndef LLIST_H
#define LLIST_H

typedef struct node_t {
	char* data;
	node_t* next;
} node_t;

node_t* makenode(char* data);

void append(node_t* head, char* data);
void remove(node_t* head);
void free_list(node_t* head);

void print_list(node_t* head);

#endif
