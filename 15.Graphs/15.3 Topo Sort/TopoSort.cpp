#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> graph, int vis[], stack<int> &s)
{
    vis[node] = 1;
    for (auto i : graph[node])
    {
        if (!vis[i])
            dfs(i, graph, vis, s);
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes)
{
    vector<int> ans;
    int v = graph.size();
    int vis[v] = {0};
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfs(i, graph, vis, s);
    }
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main()
{

    vector<vector<int>> graph = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    int V = 6;
    vector<int> ans = topologicalSort(graph,6,6);

    for (auto node : ans)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}