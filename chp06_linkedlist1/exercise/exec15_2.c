#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert(ListNode *head, element value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));	
	p->data = value;					
	p->link = head;	
	head = p;	
	return head;	
}

void print_list(ListNode *head) {
	for(ListNode *p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
		printf("NULL \n");
}

int getMax(ListNode *head) {
	int MAX = head->data;
	
	for(ListNode *p = head; p!=NULL; p=p->link) {
		if(MAX < p->data)
			MAX = p->data;
	}
	return MAX;
}

int getMin(ListNode *head) {
	int MIN = head->data;
	
	for(ListNode* p = head; p != NULL; p = p->link) {
		if (MIN > p->data)
			MIN = p->data;
	}
	return MIN;
}

int main(void) {
	int n, num;
	ListNode *head = NULL;
	
	printf("노드의 개수: ");
	scanf("%d", &n);
	
	for (int i=0; i<n; i++) {
		printf("Node #%d data: ", i);
		scanf("%d", &num);
		head = insert(head, num);
	}
	print_list(head); 
	printf("최댓값 = %d \n", getMax(head));
	printf("최솟값 = %d \n", getMin(head));
	return 0;
}