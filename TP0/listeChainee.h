
typedef struct node{
  int value;
  struct node* next_node;
} node;

node* initializer(int const value);

int get_element(node const* head, int const position);

void add_element(node* head, int const value);

void clear(node* head);

void print_nodes(node const* head);

void print_to_file(FILE* f, node const* head);
