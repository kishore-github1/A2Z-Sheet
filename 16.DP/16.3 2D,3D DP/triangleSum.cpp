#include <bits/stdc++.h>
using namespace std;

int f(vector<vector<int>> triangle, int i, int j, vector<vector<int>> &dp)
{
    int n = triangle.size();

    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == n - 1)
        return triangle[i][j];

    int down = triangle[i][j] + f(triangle, i + 1, j, dp);
    int downbeside = triangle[i][j] + f(triangle, i + 1, j + 1, dp);

    dp[i][j] = min(down, downbeside);
    return dp[i][j];
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size(), m = triangle[n - 1].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    // return f(triangle,0,0,dp);

    // Tabulation

    //Space optimization
    vector<int> nxt(m,0);
    for (int i = 0; i < m; i++)
    {
        nxt[i] = triangle[n - 1][i];
    }

    
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            int down = triangle[i][j] + nxt[j];
            int downbeside = triangle[i][j] + nxt[j+1];

            nxt[j] = min(down, downbeside);
        }
    }
    return nxt[0];
}

int main()
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << minimumTotal(triangle);

    return 0;
}