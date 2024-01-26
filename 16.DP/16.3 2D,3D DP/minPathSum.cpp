#include <bits/stdc++.h>
using namespace std;

int f(vector<vector<int>> grid, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[0][0];

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = INT_MAX, left = INT_MAX;
    if (i > 0)
        up = grid[i][j] + f(grid, i - 1, j, dp);
    if (j > 0)
        left = grid[i][j] + f(grid, i, j - 1, dp);

    return dp[i][j] = min(up, left);
}

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    // return f(grid, m - 1, n - 1, dp);

    // Tabulation
    // space optimization
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[j] = grid[i][j];
                continue;
            }
            int up = INT_MAX, left = INT_MAX;
            if (i > 0)
                up = grid[i][j] + prev[j];
            if (j > 0)
                left = grid[i][j] + temp[j - 1];
            temp[j] = min(up, left);
        }
        prev = temp;
    }
    return prev[n-1];
}
int main()
{
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}}; //{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minPathSum(grid);

    return 0;
}