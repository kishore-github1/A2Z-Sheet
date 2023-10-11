#include <bits/stdc++.h>
using namespace std;

string getAlienLanguage(vector<string> &dictionary, int k)
{
    vector<int> adj[k];
    int n = dictionary.size();
    for (int i = 0; i < n-1; i++)
    {
        string s1 = dictionary[i];
        string s2 = dictionary[i + 1];
        int l = min(s1.size(), s2.size());

        for (int ptr = 0; ptr < l; ptr++)
        {
            if (s1[ptr] != s2[ptr])
            {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }

    int indegree[k] = {0};
    for (int i = 0; i < k; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < k; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> topo;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    string ans = "";
    for (auto it : topo)
    {
        ans += char(it+'a');
    }

    return ans;
}

int main()
{
    vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
    string s = getAlienLanguage(dict, 4);
    cout << s;

    return 0;
}