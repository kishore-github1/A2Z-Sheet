#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }
    int arow[] = {1, 0, -1, 0};
    int acol[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int d = q.front().second;
        ans[r][c] = d;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + arow[i];
            int ncol = c + acol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0)
            {
                q.push({{nrow, ncol}, d + 1});
                vis[nrow][ncol] = 1;
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}