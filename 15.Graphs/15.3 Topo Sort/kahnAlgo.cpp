#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(vector<vector<int>> graph, int v)
{
    vector<int> ans;
    queue<int> q;
    int indegree[v] = {0};
    for (int i = 0; i < v; i++)
    {
        for (auto it : graph[i])
        {
            indegree[it]++;
        }
    }
    for (int i= 0;i<v;i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for(auto it:graph[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> graph = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    int V = 6;
    vector<int> ans = topoSort(graph,V);

    for (auto node : ans)
    {
        cout << node << " ";
    }
    cout << endl;


    return 0;
}