#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int arow[] = {-1, 0, 1, 0};
    int acol[] = {0, 1, 0, -1};
    stack<pair<int, int>> s;
    s.push({i, j});
    vis[i][j] = 1;

    while (!s.empty())
    {
        pair<int, int> cur = s.top();
        s.pop();

        for (int k = 0; k < 4; k++)
        {
            int nrow = cur.first + arow[k];
            int ncol = cur.second + acol[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                s.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
}

int numEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    // traversing first col and last col
    for (int i = 0; i < n; i++)
    {
        if (!vis[i][0] && grid[i][0] == 1)
            dfs(i, 0, vis, grid);

        if (!vis[i][m - 1] && grid[i][m - 1] == 1)
            dfs(i, m - 1, vis, grid);
    }
    // traversing first row and last row
    for (int j = 0; j < m; j++)
    {
        if (!vis[0][j] && grid[0][j] == 1)
            dfs(0, j, vis, grid);

        if (!vis[n - 1][j] && grid[n - 1][j] == 1)
            dfs(n - 1, j, vis, grid);
    }
    int count = 0;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
                count++;
        }
    }
    return count;
}

int main()
{

    return 0;
}