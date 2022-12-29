/*
    링크법으로 생성된 이진트리, 그리기
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;
//  		 n1
//		   / |
//		  n2  n3

TreeNode* print_tree(TreeNode* n) {
	TreeNode* tree = n;

	if (tree->data != NULL) {
		printf(" %d", tree->data);		

		if (tree->left != NULL || tree->right != NULL) {
			printf("\n");
		}

		if (tree->left != NULL) printf("  / ");
		if (tree->right != NULL) printf(" | ");
	}
	return tree;
}

int main(void)
{
	TreeNode* n1, * n2, * n3;
	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));
	n1->data = 10;		// 첫 번째 노드를 설정한다.
	n1->left = n2;
	n1->right = n3;
	print_tree(n1);
	printf("\n");		// root 
	n2->data = 20;		// 두 번째 노드를 설정한다.
	n2->left = NULL;
	n2->right = NULL;
	print_tree(n2);
	n3->data = 30;		// 세 번째 노드를 설정한다.
	n3->left = NULL;
	n3->right = NULL;
	print_tree(n3);
	free(n1); free(n2); free(n3);
	return 0;
}
