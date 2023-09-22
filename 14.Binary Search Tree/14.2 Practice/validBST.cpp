#include <bits/stdc++.h>
using namespace std;

bool isValidBST(TreeNode *root)
{
    return isvalidBST(root, LONG_MIN, LONG_MAX);
}
bool isvalidBST(TreeNode *root, long minVal, long maxVal)
{
    if (root == NULL)
        return true;
    if (root->val <= minVal || root->val >= maxVal)
        return false;
    return isvalidBST(root->left, minVal, root->val) &&
           isvalidBST(root->right, root->val, maxVal);
}

int main()
{

    return 0;
}