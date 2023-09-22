#include <bits/stdc++.h>
using namespace std;

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int i =0;
    return build(preorder,i,INT16_MAX);
}

TreeNode *build(vector<int> preorder,int &i,int bound){
    if(preorder.size()==i || preorder[i]>bound) return NULL;
    TreeNode *node = new TreeNode(preorder[i++]);
    node->left = build(preorder,i,node->val);
    node->right = build(preorder,i,bound);
    return node;
}

int main()
{

    return 0;
}