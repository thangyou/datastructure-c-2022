/*
	+ quiz_183
	clear(), replace(), get_length()
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100 	

typedef int element;			
typedef struct {
	element array[MAX_LIST_SIZE];	  
	int size;		  
} ArrayListType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init(ArrayListType* L) { L->size = 0; }
int is_empty(ArrayListType* L) { return L->size == 0; }
int is_full(ArrayListType* L) { return L->size == MAX_LIST_SIZE; }
element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)  error("위치 오류");
	return L->array[pos];
}
void print_list(ArrayListType* L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}
void insert_last(ArrayListType* L, element item)
{
	if (L->size >= MAX_LIST_SIZE) {
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}
void insert(ArrayListType* L, int pos, element item)
{
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--)
			L->array[i + 1] = L->array[i];
		L->array[pos] = item;
		L->size++;
	}
}
element delete(ArrayListType* L, int pos)
{
	element item;

	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++)
		L->array[i] = L->array[i + 1];
	L->size--;
	return item;
}
// Quiz 01의 연산 
void clear(ArrayListType* L) {
	for (int i = 0; i < L->size; i++) 
L->array[i] = 0;
	L->size = 0;
}
void replace(ArrayListType* L, int pos, element item) { L->array[pos] = item; }
element get_length(ArrayListType* L) { return L->size; }


int main(void)
{
	ArrayListType list;

	init(&list);
	insert(&list, 0, 10);	print_list(&list);	// 0번째 위치에 10 추가
	insert(&list, 0, 20);	print_list(&list);	// 0번째 위치에 20 추가
	insert(&list, 0, 30);	print_list(&list);	// 0번째 위치에 30 추가
	insert_last(&list, 40);	print_list(&list);	// 맨 끝에 40 추가
	delete(&list, 0);	print_list(&list);	// 0번째 항목 삭제
	printf("replace() ");
	replace(&list, 2, 22);  print_list(&list);
	printf("get_length() ");
	get_length(&list);	print_list(&list);
	printf("clear() ");
	clear(&list);		print_list(&list);
	return 0;
}
