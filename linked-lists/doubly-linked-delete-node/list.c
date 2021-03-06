#include <stdlib.h>
#include "list.h"

link new_link(int i) {
	link x = malloc(sizeof *x);
	x->item = i;
	x->next = NULL;
	x->prev = NULL;

	return x;
}

// Insert b after a
link insert_after(link a, link b) {
	b->next = a->next;
	if (a->next != NULL)
		a->next->prev = b;
	a->next = b;
	b->prev = a;
	
	return b;
}

link delete_after(link x) {
	link t = x->next;
	
	if (t->next != NULL)
		t->next->prev = t->prev;
	t->prev->next = t->next;
	
	return t;
}

void free_link(link x) {
	free(x);
}
