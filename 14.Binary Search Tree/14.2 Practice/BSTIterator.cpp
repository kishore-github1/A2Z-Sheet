#include <bits/stdc++.h>
using namespace std;

stack<TreeNode *> s;
BSTIterator(TreeNode *root)
{
    pushAll(root);
}

int next()
{
    TreeNode *temp = s.top();
    s.pop();
    pushAll(temp->right);
    return temp->val;
}

bool hasNext()
{
    return !s.empty();
}

void pushAll(TreeNode *root){
    for(;root!=NULL;s.push(root),root=root->left);
}

int main()
{

    return 0;
}