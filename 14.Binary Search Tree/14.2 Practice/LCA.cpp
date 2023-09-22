#include <bits/stdc++.h>
using namespace std;

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(!root) return NULL;

    int curr = root->val;
    if(curr>p->val && curr>q->val) return lowestCommonAncestor(root->left,p,q);
    if(curr<p->val && curr<q->val) return lowestCommonAncestor(root->right,p,q);
    return root;
}

int main()
{

    return 0;
}