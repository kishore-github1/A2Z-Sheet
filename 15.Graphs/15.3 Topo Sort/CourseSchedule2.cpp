#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> ans;
    int v = numCourses;
    vector<int> indegree(v,0);
    vector<vector<int>> adj(v, vector<int>());
    for (auto i : prerequisites)
    {
        adj[i[1]].push_back(i[0]);
    }
    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
            
        }
    }
    if(ans.size()==v) return ans;
    return {{}};
}

int main()
{

    return 0;
}