#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    // {to,time}
    vector<pair<int,int>> adj[n+1];
    for(auto it : times){
        adj[it[0]].push_back({it[1],it[2]});
    }

    vector<int> dist(n+1,1e9);
    dist[0]=0;
    dist[k]=0;
    //{frm , time}
    queue<pair<int,int>> q;
    q.push({k,0});

    while (!q.empty())
    {
        auto node = q.front();
        int frm = node.first;
        int time = node.second;
        q.pop();

        for(auto it : adj[frm]){
            int neighbor = it.first;
            int neighborTime = it.second;
            if(time + neighborTime < dist[neighbor]){
                dist[neighbor] = time + neighborTime;
                q.push({neighbor,dist[neighbor]});
            }
        }
    }
    int ans = INT16_MIN;
    for(auto it : dist){
        if(it == 1e9) return -1;
        if(it>ans) ans = it;
    }
    return ans;
    
}

int main()
{

    return 0;
}