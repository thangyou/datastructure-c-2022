/*
    18번은 오름차순 정렬.
    이진 탐색 트리 이용하여 배열에 저장된 숫자들을 내림차순 정렬시키는 함수 작성
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int key;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 4,&n1,NULL };
TreeNode n3 = { 16,NULL,NULL };
TreeNode n4 = { 25,NULL,NULL };
TreeNode n5 = { 20,&n3,&n4 };
TreeNode n6 = { 15,&n2,&n5 };
TreeNode* root = &n6;

void inorder(TreeNode* root)
{
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

TreeNode* new_node(int item)
{
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* insert_node(TreeNode* node, int key)
{
    if (node == NULL) return new_node(key);
    if (key > node->key)
        node->left = insert_node(node->left, key);
    else if (key < node->key)
        node->right = insert_node(node->right, key);
    return node;
}

void sort(int arr[],int size)
{
    TreeNode* root = NULL;
    for (int a = 0; a < size ; a++)
    {
        root = insert_node(root, arr[a]); //이진 탐색 트리를 만든다
    }
    inorder(root); //중위 순회하여 값을 읽어온다
}

int main(void)
{
    int arr[11] = { 11,3,4,1,56,5,6,2,98,32,23 };
    printf("현재 입력된 배열 : ");
    int size = sizeof(arr) / 4; //배열의 크기를 size 변수에 저장
    for (int a = 0; a < size; a++) //배열의 크기만큼 반복
    {
        printf("%d ", arr[a]);
    }
    printf("\n정렬 후 : ");
    sort(arr, size);

    return 0;
}
