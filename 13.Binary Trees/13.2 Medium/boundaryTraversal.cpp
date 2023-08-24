#include <bits/stdc++.h>
using namespace std;

bool isLeaf(TreeNode<int> *root)
{
    if (root->left == NULL && root->right == NULL)
        return true;
    return false;
}

void leftBoundary(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int> *curr = root;
    while (curr)
    {
        if (!isLeaf(curr))
            ans.push_back(curr->data);
        if (curr->left == NULL)
            curr = curr->right;
        else
            curr = curr->left;
    }
}

void addLeaves(TreeNode<int> *root, vector<int> &ans)
{
    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    addLeaves(root->left, ans);

    addLeaves(root->right, ans);
}

void rightBoundary(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int> *curr = root;
    vector<int> temp;
    while (curr)
    {
        if (!isLeaf(curr))
            temp.push_back(curr->data);
        if (curr->right == NULL)
            curr = curr->left;
        else
            curr = curr->right;
    }
    for (int i = temp.size() - 1; i >= 0; --i)
    {
        ans.push_back(temp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    if (!isLeaf(root))
        ans.push_back(root->data);
    leftBoundary(root, ans);
    addLeaves(root, ans);
    rightBoundary(root, ans);
    return ans;
}

int main()
{

    return 0;
}