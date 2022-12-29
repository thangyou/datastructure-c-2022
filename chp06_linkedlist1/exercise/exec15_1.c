/*
    단순 연결 리스트가 정렬되지 않은 정수들의 리스트를 저장하고 있다.
    리스트에서 최대, 최소값을 찾는 프로그램 작성하라.
	실습 06_2
*/
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;

void error(char* msg) {
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

ListNode* insert_first(ListNode *head, element value) {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode *head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d -> ", p->data);
	printf("NULL \n");
}

int find_max(ListNode* head) {
	ListNode* p = head;
	int max = p->data;
	while (p != NULL) {
		if (p->data > max)
			max = p->data;
		p = p->link;
	}
	return max;
}

int find_min(ListNode* head) {
	ListNode* p = head;
	int min = p->data;
	while (p != NULL) {
		if (p->data < min)
			min = p->data;
		p = p->link;
	}
	return min;
}

int main(void)
{
	ListNode *head = NULL;
	
	srand(time(NULL)); 	// 입력 데이터 난수 값 이용
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, rand() % 19+1);
		print_list(head);	
	}

	printf("리스트의 최대값 : %d\n", find_max(head));
	printf("리스트의 최소값 : %d\n", find_min(head));

	return 0;
}



