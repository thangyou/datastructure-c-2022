/*
    1. 단순 연결리스트에서 하나의 노드를 삭제하려면 어떤 노드를 가리키는 포인터 변수가 필요한가?
    첫 번째 노드를 가리키는 포인터의 포인터 변수, 
    삭제하려고 하는 노드의 선행 노드의 포인터 변수, 
    삭제하려는 노드의 포인터 변수

    2. 단순 연결 리스트에 존재하는 노드의 수 계산하는 get_length() 함수
*/
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode* link;
} ListNode;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// 헤드 포인터의 값을 복사	//(3)
	head = p;	// 헤드 포인터 변경		//(4)
	return head;	// 변경된 헤드 포인터 반환
}

ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = pre->link;	//(3)	
	pre->link = p;		//(4)	
	return head;		//(5)	
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;		// (1)
	head = removed->link;	// (2)
	free(removed);		// (3)
	return head;		// (4)
}
ListNode* delete(ListNode* head, ListNode* pre) 
{	// pre가 가리키는 노드의 다음 노드를 삭제한다.
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;		// (2)
	free(removed);				// (3)
	return head;				// (4)
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

element get_length(ListNode* head) {
	int cnt = 0;
	ListNode* p = head;
	while (p != NULL) {
		p = p->link;
		cnt++;
	}
	return cnt;
}

int main(void)
{
	ListNode* head = NULL;

	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}
	printf("---------------------\n");
	printf("get_length() = %d\n", get_length(head));
	printf("---------------------\n");

	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}
	return 0;
}
