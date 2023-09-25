#include <bits/stdc++.h>
using namespace std;

void dfs(vector<bool> &vis, int node, vector<int> adj[])
{
    vis[node] = true;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(vis, it, adj);
        }
    }
}

int findCircleNum(vector<vector<int>> isConnected)
{
    int count = 0;

    int V = isConnected.size();
    vector<int> adj[V];
    for (int i = 0; i < V; i++)
    {
        for (int j= 0; j < V; j++)
        {
            if(isConnected[i][j]==1 && i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        
    }
    
    vector<bool> vis(V);
    for (int i = 0; i < V; ++i)
    {
        if (!vis[i])
        {
            count++;
            dfs(vis, i, adj);
        }
    }
    return count;
}

int main()
{

    return 0;
}