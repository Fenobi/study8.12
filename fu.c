#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct TreeNode
{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
}BTNode;

BTNode* PreOrder(char* a, int* pi)
{
    if (a[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }
    
    BTNode* root = (BTNode*)malloc(sizeof(BTNode));
    if (root == NULL)
    {
        perror("malloc fail");
        exit(-1);
    }

    root->val = a[*pi];
    (*pi)++;
    root->left = PreOrder(a, pi);
    root->right = PreOrder(a, pi);
    return root;
}

void MidOrder(BTNode* BT)
{
    if (BT == NULL)
    {
        return;
    }
    else
    {
        MidOrder(BT->left);
        printf("%c ", BT->val);
        MidOrder(BT->right);
    }
}

int main()
{
    char ch[100];
    scanf("%s", &ch);
    int pi = 0;
    
    MidOrder(PreOrder(ch, &pi));
    return 0;
}