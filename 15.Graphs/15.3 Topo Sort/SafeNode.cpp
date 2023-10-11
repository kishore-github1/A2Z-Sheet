#include <bits/stdc++.h>
using namespace std;
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    vector<int> ans;
    int v = graph.size();
    vector<int> indegree(v, 0);
    vector<vector<int>> adj(v, vector<int>());
    for (int i = 0; i < v; i++)
    {
        for (auto it : graph[i])
        {
            adj[it].push_back(i);
            indegree[i]++;
        }
    }

       queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}