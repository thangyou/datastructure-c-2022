#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define max(a,b)  (((a) > (b)) ? (a) : (b))

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

int get_height(TreeNode* root)
{
    int height = 0;
    if (root != NULL)
        height = 1 + max(get_height(root->left), get_height(root->right));
    return height;
}

int isBalanced(TreeNode* node) {
	if (node == NULL)
		return 1;
	int leftHeight = get_height(node->left);
	int rightHeight = get_height(node->right);
	//왼쪽 서브트리와 오른쪽서브트리의 높이차가 2이상 나지 않고 둘 다 균형이 잡혀있을 경우 참
	if ((rightHeight - leftHeight) > -1
		&& (rightHeight - leftHeight) < 2
		&& isBalanced(node->left) && isBalanced(node->right))
		return 0;
	return 1;
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
	if (isBalanced(root) == 1) printf("균형 트리 맞음\n");
	else printf("균형 트리 아님 \n");

	return 0;
}