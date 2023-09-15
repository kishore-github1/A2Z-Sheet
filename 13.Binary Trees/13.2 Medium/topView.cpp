#include <bits/stdc++.h>
using namespace std;

vector<int> topView(Node *root)
{
    vector<int> ans;
    queue<pair<Node *, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int vl = it.second;
        if (m.find(vl) == m.end())
            m[vl] = node->data;

        if (node->left != NULL)
        {
            q.push({node->left, vl - 1});
        }
        if (node->right != NULL)
        {
            q.push({node->right, vl + 1});
        }
    }
    for (auto it : m)
    {
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{

    return 0;
}