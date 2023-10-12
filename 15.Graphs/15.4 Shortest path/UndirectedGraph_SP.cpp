#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, vector<vector<int>> &edges, int src)
{
    vector<int> adj[n];
    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    int dis[n] ;
    for (int i = 0; i < n; i++)
{
    dis[i] = INT32_MAX;
}
    dis[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (dis[node] + 1 < dis[it])
            {
                dis[it] = dis[node] + 1;
                q.push(it);
            }
        }
    }
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (dis[i] != INT32_MAX)
        {
            ans[i] = dis[i];
        }
    }
    return ans;
}

int main()
{

    return 0;
}