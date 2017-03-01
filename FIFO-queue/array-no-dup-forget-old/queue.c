#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "QUEUE.h"

static Item *q;
static int N;
static int tail;
static int head;

void QUEUEinit(int maxN) {
	q = malloc(maxN * sizeof(Item));
	N = maxN;
	head = N;
	tail = 0;
}

int QUEUEempty(void) {
	return head % N == tail;
}

void QUEUEput(Item item) {
	int i;
	
	for (i = head; i != tail; i = (i + 1) % N) {
		if (q[i] == item) {
			for (; i != tail; i = (i + 1) % N) {
				q[i] = q[(i + 1) % N];
			}
			tail = (tail == 0) ? N - 1 : tail - 1;
			break;
		}
	}
	
	q[tail++] = item;
	tail = tail % N;
}

Item QUEUEget(void) {
	head = head % N;
	return q[head++];
}
