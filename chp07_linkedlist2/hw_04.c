/*
    cir_list.c 에서 만들어진 원형 연결 리스트에서 처음과 끝의 노드 삭제하는 함수
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
	printf("%d->\n", p->data); // 마지막 노드 출력
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

element get_length(ListNode* head) {
	int cnt = 0;
	ListNode* node = head->link;

	if (node == NULL) cnt = 0;
	else {
		while (node != head) {
			node = node->link;
			cnt++;
		}
		cnt++; // pre 개수 포함!
	}
	return cnt;
}

// 첫번째 노드 삭제
ListNode* delete_first(ListNode* head) {
	ListNode* rm;
	ListNode* tmp;
	rm = head->link;

	if (rm == NULL) return NULL;
	else {
		tmp = rm->link;
		head->link = tmp;
		free(rm);
		tmp = head;
	}
	return head;
}

// 마지막 노드 삭제
ListNode* delete_last(ListNode* head) {
	ListNode* rm;
	ListNode* tmp;

	rm = head->link;
	if (rm == NULL) return NULL;
	else {
		tmp = rm->link; // tmp는 리스트의 첫번째노드
		while (tmp->link != head) { // 리스트의 마지막 노드를 앞까지 !
			tmp = tmp->link;		// 마지막 노드 바로 앞 노드까지 이동
		}
		// 리스트의 마지막 노드를 가리키면!
		head = tmp;
		head->link = rm;
		tmp = NULL;
		free(tmp);
	}
	return head;
}

// 마지막 노드 : head
// 첫번째 노드 : head->link

// 원형 연결 리스트 테스트 프로그램
int main(void)
{
	ListNode* head = NULL;

	// list =// 10->20->30->40
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	printf("get_length() : %d\n", get_length(head));
	head = delete_first(head);
	print_list(head);
	printf("get_length() : %d\n", get_length(head));
	head = delete_last(head);
	print_list(head);
	printf("get_length() : %d\n", get_length(head));

	return 0;
}
