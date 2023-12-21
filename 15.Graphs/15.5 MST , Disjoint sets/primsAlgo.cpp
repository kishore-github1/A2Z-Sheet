#include <bits/stdc++.h>
using namespace std;

// Prims algorithm is used to find the minimum spanning tree
int spanningTree(int V, vector<vector<int>> adj[])
{
    int sum = 0;
    vector<int> vis(V, 0);

    //{weight,node}
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>, greater<pair<int, int>>>
        pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        auto p = pq.top();
        int w = p.first;
        int n = p.second;
        pq.pop();

        if (vis[n])
            continue;

        sum += w;
        vis[n] = 1;

        for (auto it : adj[n])
        {
            int new_node = it[0];
            int node_weight = it[1];
            if (!vis[new_node])
                pq.push({node_weight, new_node});
        }
    }
    return sum;
}

int main()
{

    return 0;
}