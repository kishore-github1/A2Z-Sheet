#include <bits/stdc++.h>
using namespace std;

bool findTarget(TreeNode *root, int k)
{
    if (root->left == NULL && root->right == NULL)
        return false;

    unordered_set<int> s;
    queue<TreeNode *> q;

    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (s.find(node->val) != s.end())
            return true;
        s.insert(k - (node->val));
        if (node->left != NULL)
            q.push(node->left);

        if (node->right != NULL)
             q.push(node->right);
    }
    return false;
}

int main()
{

    return 0;
}