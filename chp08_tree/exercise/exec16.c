/*
    주어진 이진 트리에서 자식이 하나만 있는 노드의 개수를 반환하는 함수를 작성
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;

#define SIZE 100
int top = -1;
TreeNode *stack[SIZE];

void push(TreeNode *p)
{
	if (top < SIZE - 1)
		stack[++top] = p;
}

TreeNode *pop()
{
	TreeNode *p = NULL;
	if (top >= 0)
		p = stack[top--];
	return p;
}

void inorder_iter(TreeNode *root)
{
	while (1) {
		for (; root; root = root->left)
			push(root);
		root = pop();
		if (!root) break;
		printf("[%d] ", root->data);
		root = root->right;
	}
}

int onechildren(TreeNode *node)
{
    int cnt = 0;
    if (!node) 
        return cnt;
    else if ((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL))
        cnt = 1 + onechildren(node->left) + onechildren(node->right);
    else 
        cnt = onechildren(node->left) + onechildren(node->right);
    
    return cnt;
}

int twochildren(TreeNode *node)
{
    int cnt = 0;
    if (!node) 
        return cnt;
    else if (node->left != NULL && node->right != NULL)
        cnt = 1 + twochildren(node->left) + twochildren(node->right);
    else 
        cnt = twochildren(node->left) + twochildren(node->right);
    
    return cnt;
}

//		  15
//	   4		 20
//    1	      16  25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode *root = &n6;

int main(void)
{
	printf("중위 순회=");
	inorder_iter(root);
	printf("\n");
    printf("자식이 하나인 노드의 개수 : %d\n", onechildren(root));
    printf("자식이 둘인 노드의 개수 : %d\n", twochildren(root));
	return 0;
}
