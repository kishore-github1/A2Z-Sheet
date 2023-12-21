#include <bits/stdc++.h>
using namespace std;
// used to find MST and its sum
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUPar(int node)
    {
        // Path Compression
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int pu = findUPar(u), pv = findUPar(v);
        if (pu == pv)
            return;
        int ru = rank[pu], rv = rank[pv];
        if (ru < rv)
            parent[pu] = pv;
        else if (ru > rv)
            parent[pv] = pu;
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int pu = findUPar(u), pv = findUPar(v);
        if (pu == pv)
            return;
        int su = size[pu], sv = size[pv];
        if (su < sv)
        {
            parent[pu] = pv;
            size[v] += size[u];
        }
        else
        {
            parent[pv] = pu;
            size[u] += size[v];
        }
    }
};

int spanningTree(int V, vector<vector<int>> adj[])
{

    // {wt,{u,v}}
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int v = it[0];
            int wt = it[1];

            edges.push_back({wt, {i, v}});
        }
    }
    sort(edges.begin(), edges.end());

    int sum = 0;
    DisjointSet ds(V);

    for (auto it : edges)
    {
        int u = it.second.first;
        int v = it.second.second;
        int wt = it.first;
        if (ds.findUPar(u) != ds.findUPar(v))
        {
            ds.unionBySize(u,v);
            sum+=wt;
        }
    }
    return sum;
}

int main()
{

    return 0;
}