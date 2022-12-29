/*
    이중 연결 리스트에서 특정 값 탐색하는 search() 함수 작성하고 테스트
    // 이중 연결 리스트 L에서 data를 가지고 있는 노드 찾아서 반환
    DListNode *search(DListNode *L, element data);
*/
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {	// 이중연결 노드 타입
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// 이중 연결 리스트를 초기화
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

// 이중 연결 리스트의 노드를 출력
void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}
// 새로운 데이터를 노드 before의 오른쪽에 삽입한다.
void dinsert(DListNode *before, element data)
{
	DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}
// 노드 removed를 삭제한다.
void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

DListNode* search(DListNode *L, element data) 
{
	DListNode* p;
    for (p = L->rlink; p != L; p = p->rlink) {
        if (p->data == data)
            return p;
    }
    return NULL;
}

// 이중 연결 리스트 테스트 프로그램
int main(void)
{
	DListNode* head = (DListNode *)malloc(sizeof(DListNode));
	init(head);
	printf("추가 단계\n");
	for (int i = 0; i < 5; i++) {
		// 헤드 노드의 오른쪽에 삽입
		dinsert(head, i);
		print_dlist(head);
	}

	int num;
	printf("찾을 값 : ");
	scanf("%d", &num);
	if(search(head, num) != NULL) printf("O");
	else printf("X");

	printf("\n삭제 단계\n");
	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);
	return 0;
}