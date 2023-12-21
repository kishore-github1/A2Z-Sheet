#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Both belong to same componenet";
    }
    else
        cout << "Doesn't belong to same component";

    ds.unionBySize(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Both belong to same componenet";
    }
    else
        cout << "Doesn't belong to same component";

    return 0;
}