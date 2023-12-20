#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>> &roads)
{
    // {to, time}
    vector<pair<int, int>> adj[n];

    for (auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    vector<int> ways(n, 0);
    ways[0] = 1;

    vector<long long> time(n, LLONG_MAX); // Use long long for time
    time[0] = 0;

    int mod = static_cast<int>(1e9 + 7);

    //{time, from}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        auto node = pq.top();
        long long tm = node.first; // Use long long for time
        int frm = node.second;
        pq.pop();

        for (auto it : adj[frm])
        {
            int neighbor = it.first;
            int neighborTime = it.second;

            if (tm + neighborTime < time[neighbor])
            {
                time[neighbor] = tm + neighborTime;
                ways[neighbor] = ways[frm];
                pq.push({time[neighbor], neighbor});
            }
            else if (tm + neighborTime == time[neighbor])
            {
                ways[neighbor] = (ways[neighbor] + ways[frm]) % mod;
            }
        }
    }

    return ways[n - 1] % mod;
}

int main()
{

    return 0;
}