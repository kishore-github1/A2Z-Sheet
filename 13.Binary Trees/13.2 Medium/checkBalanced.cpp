#include <bits/stdc++.h>
using namespace std;

int depth(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lh = depth(root->left);
    int rh = depth(root->right);

    if (lh == -1 || rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;

    return 1 + max(lh, rh);
}

bool isBalanced(TreeNode *root)
{
    if(depth(root)==-1) return false;
    else return true;
}

int main()
{

    return 0;
}