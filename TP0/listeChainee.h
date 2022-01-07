#pragma once
typedef struct node {
    int value;
    struct node* next_node;
} node;

void initializer(node* head);

int get_element(node* head, int position);

void add_element(node* head, int value);

void clear(node* head);

void print_nodes(node* head);

void print_to_file();
