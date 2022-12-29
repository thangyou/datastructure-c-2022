/*
    이진 탐색 트리의 가장 큰 용도는 map(사전)이라는 자료구조 표현하는 것이다.
    본문에서는 단어장을 구현하였는데, 여기서는 친구들 연락처 저장하고 탐색해보자!
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_NAME_SIZE	 100
#define MAX_PHONE_SIZE 200

typedef struct {
	char name[MAX_NAME_SIZE];		
	char phone[MAX_PHONE_SIZE];
} element;

typedef struct TreeNode {
	element key;
	struct TreeNode *left, *right;
} TreeNode;

int compare(element e1, element e2)
{
	return strcmp(e1.name, e2.name);
}

TreeNode* search(TreeNode *root, element key)
{
	TreeNode* p = root;
	while (p != NULL) {
		if (compare(key, p->key) == 0)
			return p;
		else if (compare(key, p->key) < 0)
			p = p->left;
		else if (compare(key, p->key) > 0)
			p = p->right;
	}
	return p; 	
}
TreeNode* new_node(element item)
{
	TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* insert_node(TreeNode* node, element key)
{
	if (node == NULL) return new_node(key);

	if (compare(key, node->key)<0)
		node->left = insert_node(node->left, key);
	else if (compare(key, node->key)>0)
		node->right = insert_node(node->right, key);

	return node;
}
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode *current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}
TreeNode* delete_node(TreeNode* root, element key)
{
	if (root == NULL) return root;

	if (compare(key, root->key)<0)
		root->left = delete_node(root->left, key);
	if (compare(key, root->key)>0)
		root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		TreeNode *temp = min_value_node(root->right);
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

void help()
{
	printf("\n삽입(i), 탐색(s), 삭제(d) : ");
}
int main(void)
{
	char command;
	element e;
	TreeNode* root = NULL;
	TreeNode* tmp;

	do {
		help();
		command = getchar();
		getchar();		// 엔터키 제거
		switch (command) {
		case 'i':
			printf("친구의 이름 : ");
			gets(e.name);
			printf("친구의 전화번호 : ");
			gets(e.phone);
			root = insert_node(root, e);
			break;
		case 's':
			printf("친구의 이름 : ");
			gets(e.name);
			tmp = search(root, e);
			if (tmp != NULL)
				printf("친구의 전화번호 : %s", e.phone);
			else
			    printf("존재하지 않습니다.");
			break;
        case 'd':
			printf("친구의 이름 : ");
			gets(e.name);
			root=delete_node(root, e);
			break;
		}
	} while (command != 'q');
	return 0;
}