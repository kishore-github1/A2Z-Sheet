#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    // {to,price}
    vector<pair<int, int>> adj[n];
    for (auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }

    vector<int> cost(n, 1e9);
    cost[src] = 0; 
    //{from,{price,no of stops }}
    queue<pair<int, pair<int, int>>> q;
    q.push({src, {0, 0}});

    while (!q.empty())
    {
        pair<int, pair<int, int>> node = q.front();
        int s = node.first;
        int price = node.second.first;
        int stops = node.second.second;
        q.pop();

       for (auto it : adj[s]) {
            int neighbor = it.first;
            int neighborPrice = it.second;

            if (stops <= k && (price + neighborPrice) < cost[neighbor]) {
                cost[neighbor] = price + neighborPrice;
                q.push({neighbor, {cost[neighbor], stops + 1}});
            }
        }
    }

    return (cost[dst] == 1e9) ? -1 : cost[dst];
}

int main()
{

    return 0;
}