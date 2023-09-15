#include <bits/stdc++.h>
using namespace std;

TreeNode *deleteNode(TreeNode *root, int key)
{
    while (!root)
        return NULL;

    if (root->val == key)
     return  helper(root, key);

    TreeNode *temp = root;
    while (root != NULL)
    {
        if (key < root->val)
        {
            if (root->left != NULL && root->left->val == key)
            {
                root->left = helper(root->left, key);
                break;
            }
            else
                root = root->left;
        }
        else if (key > root->val)
        {
            if (root->right != NULL && root->right->val == key)
            {
                root->right = helper(root->right, key);
            }
            else
                root = root->right;
        }
    }
    return temp;
}

TreeNode *helper(TreeNode *root,int key){
    if(root->left==NULL) return root->right;
    if(root->right==NULL) return root->left;

    TreeNode *rightChild = root->right;
    TreeNode *leftLast = rightMost(root->left);
    leftLast->right= rightChild;
    return root->left;
    
}

TreeNode *rightMost(TreeNode *root){
    if(root->right==NULL) return root;
   return rightMost(root->right);
}

int main()
{

    return 0;
}