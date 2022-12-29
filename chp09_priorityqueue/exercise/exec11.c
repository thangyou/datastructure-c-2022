/*
    자신의 할 일에 우선순위를 매겨서 힙에 저장했다가 우선순위 순으로 꺼내어 출력하는 프로그램
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct element {
	char todo[50];
	int prior;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// 생성 함수
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}
// 초기화 함수
void init(HeapType* h)
{
	h->heap_size = 0;
}
// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
// 삽입 함수
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.prior > h->heap[i / 2].prior)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // 새로운 노드를 삽입
}
// 삭제 함수
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// 현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) &&
			(h->heap[child].prior) < h->heap[child + 1].prior)
			child++;
		if (temp.prior >= h->heap[child].prior) break;
		// 한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void heap_sort(element a[], int n)
{
	int i;
	HeapType* h;

	h = create();
	init(h);
	for (i = 0; i<n; i++) {
		insert_max_heap(h, a[i]);
	}
	for (i = (n - 1); i >= 0; i--) {
		a[i] = delete_max_heap(h);
	}
	free(h);
}


void help()
{
	printf("\n삽입(i), 삭제(d) : ");
}
#define SIZE 8
int main(void)
{
	char command;
	element e;
	HeapType* heap = NULL;
	HeapType* tmp;
	heap = create(); 	// 히프 생성
	init(heap);	// 초기화

	do {
		help();
		command = getchar();
		getchar();		// 엔터키 제거
		switch (command) {
		case 'i':
			printf("할일 : ");
			gets(e.todo);
			printf("우선순위 : ");
			gets(e.prior);
			insert_max_heap(heap, e);
			heap_sort(heap->heap, SIZE);
			break;
        case 'd':
			printf("할일 : ");
			gets(e.todo);
			// heap->heap = delete_max_heap(heap);
			printf("제일 우선 순위가 높은 일은 \"%s\" \n", e.prior);
			break;
		}
	} while (command != 'q');
	return 0;
}