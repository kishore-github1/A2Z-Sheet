#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[n];
    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }
    queue<pair<int, int>> q;
    vector<int> dis(n, INT32_MAX);
    dis[0] = 0;
    q.push(adj[0]);
    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();
        for (auto it : adj[node.first])
        {
            if (it.second + dis[node.first] < dis[it.first])
                dis[it.first] = dis[node.first] + node.second;
        }
    }

    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (dis[i] != INT32_MAX)
            ans[i] = dis[i];
    }

    return ans;
}

int main()
{

    return 0;
}