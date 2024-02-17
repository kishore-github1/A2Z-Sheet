#include <bits/stdc++.h>
using namespace std;

int sol(vector<int> weight, vector<int> value, int n, int maxWeight, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (weight[0] <= maxWeight)
            return value[0];
        else
            return 0;
    }
    if (dp[n][maxWeight] != -1)
        return dp[n][maxWeight];

    int nottake = sol(weight, value, n - 1, maxWeight, dp);

    int take = 0;
    if (weight[n] <= maxWeight)
        take = value[n] + sol(weight, value, n - 1, maxWeight - weight[n], dp);

    dp[n][maxWeight] = max(nottake, take);

    return dp[n][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    // return sol(weight, value, n, maxWeight, dp);

    // Tabulation

    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        dp[0][i] = value[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            int nottake = dp[i - 1][j];

            int take = 0;
            if (weight[i] <= j)
                take = value[i] + dp[i - 1][j - weight[i]];

            dp[i][j] = max(nottake, take);
        }
    }
    return dp[n-1][maxWeight];
}

int main()
{

    return 0;
}