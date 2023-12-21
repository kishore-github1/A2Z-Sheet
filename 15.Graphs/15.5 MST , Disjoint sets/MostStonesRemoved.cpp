#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {

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

int removeStones(vector<vector<int>> &stones)
{
    int n = stones.size();
    int maxrow = 0, maxcol = 0;
    for (auto it : stones)
    {
        maxrow = max(maxrow, it[0]);
        maxcol = max(maxcol, it[1]);
    }
    DisjointSet ds(maxrow + maxcol + 1);
    unordered_map<int, int> m;
    for (auto it : stones)
    {
        int u = it[0];
        int v = it[1] + maxrow + 1;
        ds.unionBySize(u, v);
        m[u] = 1;
        m[v] = 1;
    }
    int comp = 0;
    for (auto it : m)
    {
        if (ds.findUPar(it.first) == it.first)
            comp++;
    }
    return n - comp;
}

int main()
{

    return 0;
}