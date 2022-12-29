/*
    단순 연결 리스트 C를 두 개의 연결 리스트로 분리하는 함수 split()
	연결 리스트 C의 요소가 n개라면 n번 반복, 시간복잡도는 O(n)
*/
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode *link;
} ListNode;

// 오류 처리 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode *head, int value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// 헤드 포인터의 값을 복사	//(3)
	head = p;	// 헤드 포인터 변경		//(4)
	return head;	// 변경된 헤드 포인터 반환
}

// 노드 pre 뒤에 새로운 노드 삽입
ListNode*  insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = pre->link;	//(3)	
	pre->link = p;		//(4)	
	return head;		//(5)	
}

ListNode* delete_first(ListNode *head)
{
	ListNode *removed;
	if (head == NULL) return NULL;
	removed = head;	// (1)
	head = removed->link;	// (2)
	free(removed);		// (3)
	return head;		// (4)
}
// pre가 가리키는 노드의 다음 노드를 삭제한다. 
ListNode* delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;		// (2)
	free(removed);			// (3)
	return head;			// (4)
}

void print_list(ListNode *head)
{
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

void split(ListNode *a, ListNode *b, ListNode *c) {
    int i = 1;
    for (ListNode *p = c; p!=NULL; p=p->link, i++) {
        if (i%2 == 0) {
            b = insert_first(b, p->data);
        } else {
            a = insert_first(a, p->data);
        }
    }
    print_list(a);
	print_list(b);
}

int main(void)
{
	ListNode *head = NULL;
	ListNode *a = NULL;
	ListNode *b = NULL;

	for (int i = 1; i < 10; i++) {
		head = insert_first(head, i);
	}
	print_list(head);
	split(a, b, head);
	
	return 0;
}