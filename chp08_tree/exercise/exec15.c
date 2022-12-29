/*
    주어진 이진트리에서 노드가 가진 값이 주어진 value보다 작으면 노드의 값을 출력하는 프로그램
*/
#include <stdio.h>
typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 4,&n1,NULL };
TreeNode n3 = { 16,NULL,NULL };
TreeNode n4 = { 25,NULL,NULL };
TreeNode n5 = { 20,&n3,&n4 };
TreeNode n6 = { 15,&n2,&n5 };
TreeNode* root = &n6;

void search(TreeNode* root, int scan){
    if (root != NULL) {
        if (root->data < scan)
            printf("%d보다 작은 노드 : %d\n", scan, root->data);
        search(root->left, scan);
        search(root->right, scan);
    }
}

int main(void){
    printf("\n값을 입력하시오 :");
    int scan;
    scanf("%d", &scan);
    search(root, scan);
    return 0;
}
