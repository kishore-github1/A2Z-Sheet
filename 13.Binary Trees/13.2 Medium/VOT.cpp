#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<pair<TreeNode *, pair<int, int>>> q;
    map<int, map<int, multiset<int>>> m;
    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode *node = p.first;
        int x = p.second.first, y = p.second.second;
        m[x][y].insert(node->val);
        if (node->left)
        {
            q.push({node->left, {x - 1, y + 1}});
        }
        if (node->right)
        {
            q.push({node->right, {x + 1, y + 1}});
        }
    }
    for (auto a : m)
    {
        vector<int> temp;
        for (auto i : a.second)
        {
            temp.insert(temp.end(), i.second.begin(), i.second.end());
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{

    return 0;
}