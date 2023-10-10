#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> adj, vector<int> &vis, vector<int> &pathVis)
{
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, adj, vis, pathVis) == false)
                return false;
        }
        else if (pathVis[it])
        {
            return false;
        }
    }
    pathVis[node] = 0;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    int v = numCourses;
    vector<int> vis(v, 0);
    vector<int> pathVis(v, 0);
    vector<vector<int>> adj(v,vector<int>());
    for (auto i : prerequisites)
    {
        adj[i[0]].push_back(i[1]);
    }
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, pathVis) == false)
                return false;
        }
    }

    return true;
}

int main()
{

    return 0;
}