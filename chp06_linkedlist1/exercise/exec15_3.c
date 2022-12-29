#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode
{
    element data;
    struct ListNode *link;
} ListNode;

void insert_node(ListNode **head, element h)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    if (p == NULL)
        return;
    p->data = h;
    p->link = NULL;
    if (*head == NULL)
        *head = p;
    else
    {
        ListNode *tmp = *head;
        while (tmp->link != NULL)
            tmp = tmp->link;
        tmp->link = p;
    }
}

int checkmini(ListNode *head)
{
    ListNode *tmp = head;
    int mini = tmp->data;
    for (tmp; tmp != NULL; tmp = tmp->link)
        if (mini > tmp->data)
            mini = tmp->data;
    return mini;
}

int checkmaxi(ListNode *head)
{
    ListNode *tmp = head;
    int maxi = tmp->data;
    for (tmp; tmp != NULL; tmp = tmp->link)
        if (maxi < tmp->data)
            maxi = tmp->data;
    return maxi;
}

int main(void)
{
    ListNode *head = NULL;
    int data;
    int maxi2, mini2;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &data);
        insert_node(&head, data);
    }
    mini2 = checkmini(head);
    maxi2 = checkmaxi(head);
    printf("최솟값은 %d, 최댓값은 %d입니다.\n", mini2, maxi2);
    return 0;
}
