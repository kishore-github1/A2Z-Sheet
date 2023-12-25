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

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    int n = accounts.size();
    unordered_map<string, int> mapMailNode;
    DisjointSet ds(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < accounts[i].size(); j++)
        {
            if (mapMailNode.find(accounts[i][j]) == mapMailNode.end())
            {
                mapMailNode[accounts[i][j]] = i;
            }
            else
            {
                ds.unionBySize(i, mapMailNode[accounts[i][j]]);
            }
        }
    }

    vector<string> add[n];
    for (auto it : mapMailNode)
    {
        string s = it.first;
        int node = ds.findUPar(it.second);
        add[node].push_back(s);
    }

    vector<vector<string>> ans;
    for (int i = 0; i < n; i++)
    {
        if (add[i].size() == 0)
            continue;
        string name = accounts[i][0];
        vector<string> temp;
        sort(add[i].begin(), add[i].end());
        temp.push_back(name);
        for (auto it : add[i])
        {
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}