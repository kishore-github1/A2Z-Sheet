#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>> matrix, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0 || j >= matrix.size())
        return 1e9;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == 0)
    {
        return matrix[i][j];
    }

    int l = matrix[i][j] + f(i - 1, j - 1, matrix, dp);
    int r = matrix[i][j] + f(i - 1, j + 1, matrix, dp);
    int u = matrix[i][j] + f(i - 1, j, matrix, dp);

    return dp[i][j] = min(l, min(r, u));
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // int mini = INT_MAX;
    // for (int i = 0; i < n; i++)
    // {
    //     int res = f(n - 1, i, matrix, dp);
    //     cout << res << endl;
    //     mini = min(mini, res);
    // }
    // return mini;

    // Tabulation
    // vector<vector<int>> dp(n, vector<int>(n, 0));

    // for (int i = 0; i < n; i++)
    // {
    //     dp[0][i] = matrix[0][i];
    // }

    // Space optimization
    vector<int> prev = matrix[0];

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            int l = 1e9, r = 1e9;
            if (j - 1 >= 0)
                l = matrix[i][j] + prev[j - 1];

            int u = matrix[i][j] + prev[j];

            if (j + 1 < n)
                r = matrix[i][j] + prev[j + 1];

            curr[j] = min(l, min(r, u));
        }
        prev = curr;
    }
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, prev[i]);
    }
    return mini;
}

int main()
{
    vector<vector<int>> matrix = {{-80, -13, 22}, {83, 94, -5}, {73, -48, 61}}; //= {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << minFallingPathSum(matrix);

    return 0;
}