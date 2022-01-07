#include <stdio.h>

#include "listeChainee.h"


int main(void) {
	node n = node{ 0, NULL };
	printf("%i", get_element(&n, 0));
	return 0;
}
