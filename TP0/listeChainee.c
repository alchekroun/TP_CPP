#include <stddef.h>

#include "listeChainee.h"

int get_element(node const* head, int const position) {
	if (head == NULL) {
		return -1;
	}

	if (position == 0) {
		return head->value;
	}

	return get_element(head->next_node, position - 1);
}
