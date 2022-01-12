#include <stdio.h>
#include <stdlib.h>

#include "listeChainee.h"


int main(void) {
	node* n = initializer(0);
	add_element(n, 1);
	printf("%i\n", get_element(n, 1));
	print_nodes(n);
	clear(n);
	node* n_2 = initializer(15);
	add_element(n_2, 30);
	add_element(n_2, 45);
	print_nodes(n_2);

	FILE* fp = fopen("output.txt", "w");
	print_to_file(fp, n_2);

	return 0;
}
