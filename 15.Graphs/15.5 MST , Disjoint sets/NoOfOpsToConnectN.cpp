#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{

public:
    vector<int> rank, parent, size;

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

int makeConnected(int n, vector<vector<int>> &connections)
{
    int extraEdges = 0;
    DisjointSet ds(n);

    for (auto it : connections)
    {
        int u = it[0];
        int v = it[1];
        if (ds.findUPar(u) == ds.findUPar(v))
        {
            extraEdges++;
        }
        else
            ds.unionBySize(u, v);
    }
    int comp = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == ds.parent[i])
            comp++;
    }
    if (extraEdges >= comp - 1)
        return comp - 1;
    return -1;
}

int main()
{

    return 0;
}