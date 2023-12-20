#include <bits/stdc++.h>
using namespace std;

int minimumOperations(int n, int start, int end, vector<int> &a)
{
    if (start == end)
        return 0;
    vector<int> dist(100000, 1e9);
    dist[start] = 0;

    //{node,steps}
    queue<pair<int, int>> q;
    q.push({start, 0});

    int mod = 1e5;

    while (!q.empty())
    {
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();

        for (auto it : a)
        {
            int res = (node * it) % mod;
            if (steps + 1 < dist[res])
            {
                dist[res] = steps + 1;
                if (res == end)
                    return steps+1 ;
                q.push({res, steps+1});
            }
        }
    }
    return -1;
}

int main()
{

    return 0;
}