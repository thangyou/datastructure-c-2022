/*
    원형 연결 리스트에 존재하는 노드의 수를 계산하는 함수 get_length()를 작성하라.
*/
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode* link;
} ListNode;

// 리스트의 항목 출력
void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data); // 마지막 노드 출력
}

ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;			// (2)
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;			// (2)
		head = node;				// (3)
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}

// 노드 수 계산 
element get_length(ListNode* head) {
	int cnt = 0;
	ListNode* node = head->link;

	if (node == NULL) cnt = 0;
	else {
		while (node != head) {
			node = node->link;
			cnt++;
		}
		cnt++;
	}

	return cnt;
}

// 원형 연결 리스트 테스트 프로그램
int main(void)
{
	ListNode* head = NULL;

	// list = 10->20->30->40
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);

	printf("\nget_length() : %d\n", get_length(head));
	return 0;
}
