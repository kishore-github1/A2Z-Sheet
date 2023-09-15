#include <bits/stdc++.h>
using namespace std;

bool sym(TreeNode *r1, TreeNode *r2)
{
    if (r1 == NULL || r2 == NULL)
        return r1 == r2;

    return (r1->val == r2->val) && sym(r1->left, r2->right)
    &&sym(r1->right, r2->left);
}

bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true;
    return sym(root->left, root->right);
}

int main()
{

    return 0;
}