#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define max(a,b)  (((a) > (b)) ? (a) : (b))

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  NULL,  NULL };
TreeNode n3 = { '*',  &n1,  &n2 };
TreeNode n4 = { 16, NULL, NULL };
TreeNode n5 = { 25, NULL, NULL };
TreeNode n6 = { '+', &n4,  &n5 };
TreeNode n7 = { '+', &n3,  &n6 };
TreeNode* exp = &n7;

int evaluate(TreeNode* root) {
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return root->data;
	else {
		int op1 = evaluate(root->left);
		int op2 = evaluate(root->right);
		printf("%d %c %d을 계산합니다.\n", op1, root->data, op2);
		switch (root->data) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
		}
	}
	return 0;
}

int get_node_count(TreeNode* node) { // 노드 개수 구하기
	int count = 0;

	if (node != NULL)
		count = 1 + get_node_count(node->left) +
		get_node_count(node->right);

	return count;
}

int get_leaf_count(TreeNode* node) { // 단말노드 개수 구하기
	int count = 0;

	if (node != NULL) {
		if (node->left == NULL && node->right == NULL)
			return 1;
		else
			count = get_leaf_count(node->left) +
			get_leaf_count(node->right);
	}
	return count;
}

int get_height(TreeNode* node) { // 높이 구하기
	int height = 0;

	if (node != NULL)
		height = 1 + max(get_height(node->left),
			get_height(node->right));

	return height;
}

int main(void)
{
	printf("수식의 값은 %d입니다. \n", evaluate(exp));
	printf("\n--- 8장 실습 ---");
	printf("\n노드의 총 개수 = %d", get_node_count(exp));
	printf("\n단말노드의 총 개수 = %d", get_leaf_count(exp));
	printf("\n트리의 높이 = %d", get_height(exp));

	return 0;
}
