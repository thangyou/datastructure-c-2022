/*
    정렬되지 않은 배열(array)을 이용하여 우선순위 큐 추상자료형의 각종 연산들 구현
    create, init, is_empty, is_full, insert, delete, find
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct HeapType* link;
} HeapType;

HeapType* pQueue = NULL;
int cnt = 0;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

int is_empty() { return (cnt == 0); }

int is_full() { return 0; }

HeapType* init(int data)
{
	HeapType *new_node = (HeapType *)malloc(sizeof(HeapType));
	new_node->data = data;
	new_node->link = NULL;
	return new_node;
}


void insert(int data)
{
	HeapType *current;
	HeapType *prev;
	HeapType *new_node;
	if (is_empty()) pQueue = init(data);
	else {
		prev = NULL;
		current = pQueue;
		new_node = init(data);
		while (current) {
			if (current->data < new_node->data)
				break;
			prev = current;
			current = current->link;
		}
		if (prev == NULL) {
			new_node->link = pQueue;
			pQueue = new_node;
		}
		else {
			new_node->link = prev->link;
			prev->link = new_node;
		}
	}
	cnt++;
}

void delete() {
	HeapType* del = NULL;
	if (!pQueue) return;
	del = pQueue;
	pQueue = pQueue->link;
	free(del);
	cnt--;
}

int find() {
	if (is_empty()) return -1;
	return pQueue->data;
}

void print_node() {
	HeapType* head = pQueue;
	printf("List : (");
	while (head) {
		printf("%d", head->data);
		if (!(head->link)) {
			head = head->link;
		}
		else {
			printf(", ");
			head = head->link;
		}
	}
	printf(")\n");
}

int main(void) {
	HeapType *pQueue = create();

	init(20); 	print_node();
	insert(12); 	print_node();
	insert(3); 	print_node();
	insert(2); 	print_node();
	delete();	print_node();
	insert(5); 	print_node();
	insert(16); 	print_node();
	delete();	print_node();
	insert(1); 	print_node();
	printf("find max = %d\n\n", find());
	free(pQueue);
	return 0;
}
