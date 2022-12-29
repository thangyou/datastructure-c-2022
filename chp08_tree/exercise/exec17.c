/*
    일반 이진 트리에서 최대, 최소값 탐색 함수
    이진 탐색 트리가 아님!
    * 순환호출 사용
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 4,&n1,NULL };
TreeNode n3 = { 16,NULL,NULL };
TreeNode n4 = { 25,NULL,NULL };
TreeNode n5 = { 20,&n3,&n4 };
TreeNode n6 = { 15,&n2,&n5 };
TreeNode* root = &n6;

int Min(TreeNode* root)
{
    if (root == NULL)
        return 9999;
    else
    {
        int temp = root->data;
        if (temp > Min(root->left))
            temp = Min(root->left);
        if (temp > Min(root->right))
            temp = Min(root->right);
        return temp;
    }
}

int Max(TreeNode* root)
{
    if (root == NULL)
        return -9999;
    else
    {
        int temp = root->data;
        if (temp < Max(root->left))
            temp = Max(root->left);
        if (temp < Max(root->right))
            temp = Max(root->right);
        return temp;
    }
}

int main(void)
{
    printf("최소값 : %d\n", Min(root));
    printf("최대값 : %d\n", Max(root));

    return 0;
}
