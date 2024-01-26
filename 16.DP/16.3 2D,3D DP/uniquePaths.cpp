#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>> &dp)
{
    // if (i >= m || j >= n)
    //     return 0;
    // if (i == m - 1 && j == n - 1)
    //     return 1;
    // if (dp[i][j] != -1)
    //     return dp[i][j];

    // int r = f(i, j + 1, m, n,dp);
    // int d = f(i + 1, j, m, n,dp);

    // return dp[i][j] = r + d;

    if (i < 0 || j < 0)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    int r = f(i, j - 1, dp);
    int d = f(i - 1, j, dp);
    return dp[i][j] = r + d;
}

int uniquePaths(int m, int n)
{
    // vector<vector<int>> dp(m, vector<int>(n, -1));

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
                temp[j] = 1;
                continue;
            }
            int r = 0, d = 0;
            if (j > 0)
            {
                r = temp[j - 1];
            }
            if (i > 0)
                d = prev[j];
            temp[j] = r + d;
        }
        prev = temp;
    }
    return prev[n - 1];

    // return f(m - 1, n - 1, dp);
}

int main()
{
    int m = 3, n = 7;
    cout << "Number of Unique Paths: " << uniquePaths(m, n);

    return 0;
}