/*
    다음과 같이 단순 연결 리스트에 사용자가 입력하는 값을 저장했다가 출력하는 프로그램을 작성하라.
*/
#include <stdio.h>
#include <stdlib.h>

#define element int
typedef struct ListNode{
    element data;
    struct ListNode* link;
} ListNode;

typedef struct list {
    ListNode *cur;
    ListNode *head;
    ListNode *tail;
} linkedList;

void insert(linkedList *L, element value){
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data=value;
    node->link=NULL;
    if(L->head==NULL&&L->tail==NULL){
        L->head=L->tail=node;
    }else{
        L->tail->link=node;
        L->tail=node;
    }
}

void printList(linkedList *L){
    ListNode *p = L->head;
    while(p != NULL){
        printf(" %d ",p->data);
        if(p->link!=NULL)
            printf("->");
        p=p->link;
    }
}

int main(void){
    linkedList *L = (linkedList *)malloc(sizeof(linkedList));
    L->head=NULL;
    L->tail=NULL;

    int n;
    element input;

    printf("노드의 개수 :");
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        printf("노드 #%d 데이터 :", i+1);
        scanf("%d",&input);

        insert(L, input);
    }

    printList(L);

    return 0;
}
