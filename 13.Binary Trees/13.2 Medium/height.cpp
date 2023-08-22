#include <bits/stdc++.h>
using namespace std;

int maxDepth(TreeNode *root)
{
    if (root == NULL) return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1+max(lh,rh);
}

int main()
{

    return 0;
}