/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*Search how many node do we have*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};





int nodeCount(struct TreeNode* root){
    /*The end of node*/
    if (root == NULL){
        return 0;
    }
    /*Using Recursion*/
    return (nodeCount(root->left)+nodeCount(root->right))+1;
}

void Search_Value(struct TreeNode *root, int *res, int *size){
    if(root==NULL){
        return;
    }
    
    res[(*size)++]=root->val;
    Search_Value(root->left,res,size);
    Search_Value(root->right,res,size);
}



int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int num = nodeCount(root);
    //printf("%d",num);
    
    int *result = (int *)malloc(sizeof(int)*num+1);
    *returnSize = 0;
    Search_Value(root,result,returnSize);
    
    
    return result;
}

int main(int argc, char const *argv[])
{
    struct TreeNode *node1,*node2,*node3;
    
    node1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));    
    node2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node3 = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    node1->val = 1;
    node1->left=NULL;
    node1->right = node2;

    node2->val = 2;
    node2->left=node3;
    node2->right = NULL;

    node3->val = 3 ;
    node3->left = NULL;
    node3->right = NULL;
    
    int size = 0;
    int* res = NULL;
    res = preorderTraversal(node1,&size);
    //printf("%d",*(res+2));
    int len = nodeCount(node1);
    for (int i = 0 ; i <len; i++){
        printf("%d",*(res+i));
    }
}
