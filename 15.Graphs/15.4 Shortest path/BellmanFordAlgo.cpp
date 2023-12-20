#include <bits/stdc++.h>
using namespace std;

// Dijkstras wont work when graph contains negative weights
vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> dist(V, 1e8);
    dist[S] = 0;

    // Relax N-1 cycles

    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if (dist[u] != 1e8 && w + dist[u] < dist[v])
            {
                dist[v] = w + dist[u];
            }
        }
    }
    // checking if distances reduces after N-1 iterations
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int w = it[2];

        if (dist[u] != 1e8 && w + dist[u] < dist[v])
        {
            return {-1};
        }
    }
    return dist;
}

int main()
{

    return 0;
}