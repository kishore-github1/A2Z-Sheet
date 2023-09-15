#include <bits/stdc++.h>
using namespace std;

TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == NULL || root->val == val) return root;

    if(val<root->val) return searchBST(root->left,val);
    if(val>root->val) return searchBST(root->right,val);

    return NULL ;
}

int main()
{

    return 0;
}