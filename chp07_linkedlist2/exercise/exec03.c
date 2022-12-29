/*
    원형 연결 리스트에서 특정 값 탐색하는 search() 함수 작성하고 테스트
    // 원형 연결 리스트 L에서 data를 가지고 있는 노드 찾아서 반환
    ListNode *search(ListNode *L, element data);
*/
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct CListNode {
	element data;
	struct CListType* link;
}CListNode;

void print_list(CListNode* head) {
	CListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data); // 마지막 노드 출력
}

CListNode* insert_first(CListNode* head, element data) {
	CListNode* node = (CListNode*)malloc(sizeof(CListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head; // 변경된 헤드 포인터 반환
}

CListNode* insert_last(CListNode* head, element data) {
	CListNode* node = (CListNode*)malloc(sizeof(CListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head; // 변경된 헤드 포인터 반환
}

CListNode* search(CListNode* head, element data) {
	CListNode* p = head;
	do {
		if (p->data == data)
			return p;
		p = p->link;
	} while (p != head);
	return NULL;
}

int main(void) {
	CListNode *head = NULL;
	int item;

	head = insert_last(head, 2);
	head = insert_last(head, 3);
	head = insert_last(head, 4);
	head = insert_first(head, 1);
	print_list(head);

	printf("\n원형 리스트 안에서 찾을 값 : ");
	scanf("%d", &item);
	if (search(head, item)) printf("리스트 안에 %d가 있습니다.", item);
	else printf("리스트 안에 % d가 없습니다.", item);

	return 0;
}
