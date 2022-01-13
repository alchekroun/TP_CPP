#include <stdlib.h>
#include <stdio.h>

#include "listeChainee.h"

node* initializer(int const value){
	node* n = (node*) malloc(sizeof(struct node));
	n->value = value;
	n->next_node = NULL;
	return n;
}

int get_element(node const* head, int const position) {
	if (head == NULL) {
		return -1;
	}

	if (position == 0) {
		return head->value;
	}

	return get_element(head->next_node, position - 1);
}

void add_element(node* head, int const value){
	if (head == NULL){
		return;
	}

	if (head->next_node == NULL) {
		node* n = initializer(value);
		head->next_node = n;
	} else{
		add_element(head->next_node, value);
	}
}

void clear(node* head){
	node* curr_node = head;

    while (curr_node != NULL) {
		node* next_node = curr_node->next_node;
		free(curr_node);
		curr_node = next_node;
	}

	head = NULL;
}

void print_nodes(node const* head){
	if (head == NULL){
		return;
	}

	printf("Value : %i\n", head->value);
	print_nodes(head->next_node);
}

void print_to_file(FILE* f, node const* head){
	if (f == NULL){
		printf("File not found");
		return;
	}

	if (head == NULL) {
		return;
	}

	fprintf(f, "Value = %i\n", head->value);
	print_to_file(f, head->next_node);

}
