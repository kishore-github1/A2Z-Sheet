#include <bits/stdc++.h>
using namespace std;

void solution(TreeNode *root, vector<int> &ans, int level)
{
    if (!root)
        return;
    if (level == ans.size())
        ans.push_back(root->val);
    solution(root->right, ans, level + 1);
    solution(root->left, ans, level + 1);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    int level = 0;
    solution(root, ans, level);
    return ans;
}

int main()
{

    return 0;
}