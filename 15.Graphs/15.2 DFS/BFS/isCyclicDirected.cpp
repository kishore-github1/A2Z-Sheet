#include <bits/stdc++.h>
using namespace std;
bool dfsCheck(int vis[], int pathVis[], vector<vector<int>> edges, int node)
{
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto i : edges[node])
    {
        if (!vis[i])
        {
            if (dfsCheck(vis, pathVis, edges, i) == true)
                return true;
        }
        else if (pathVis[i])
        {
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}
bool isCyclic(vector<vector<int>> &edges, int v, int e)
{
    int vis[v]={0};
    int pathVis[v]={0};
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if (dfsCheck(vis, pathVis, edges, i) == true)
                return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}