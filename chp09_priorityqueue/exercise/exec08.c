/*
    최소 히프 구현 배열 내용이 다음과 같을 때 해당하는 히프트리를 그려라.
	a[i] = { INF, 2, 9, 18, 6, 15, 7, 3, 14 }
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct {
	int key;
} element;

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
// 최소 히프는 부모 노드의 키값 <= 자식 노드의 키값 
// 따라서 최대 히프에서 부등호만 달라진다.
void insert_min_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // 새로운 노드를 삽입
}
// 삭제 함수
element delete_min_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// 현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) break;
		// 한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

HeapType* heap_sort(HeapType *heap, element a[], int n)
{
	int i;
	HeapType* h = heap;

	for (i = 0; i<n; i++) {
		insert_min_heap(h, a[i]);
	}
	// for (i = (n - 1); i >= 0; i--) {
	// 	a[i] = delete_min_heap(h);
	// }
	// free(h);
}

void print_heap(HeapType *h)
{
    for (int i = 0; i < h->heap_size; i++)
    {
        printf("%d ", h->heap);
    }
    printf("\n");
}

#define SIZE 8
int main(void)
{
    HeapType *h;
    h = create();
	init(h);

    element list[SIZE] = { 2, 9, 18, 6, 15, 7, 3, 14 };
    h = heap_sort(h, list, SIZE);
    print_heap(h);
	// for (int i = 0; i < SIZE; i++) {
	// 	printf("%d ", list[i].key);
	// }
	// printf("\n");
    free(h);
	return 0;
}