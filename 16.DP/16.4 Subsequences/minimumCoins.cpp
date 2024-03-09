#include <bits/stdc++.h>
using namespace std;

int f(vector<int> coins, int ind, int target, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (coins[0] % target == 0)
            return target / coins[0];
        else
            return INT_MAX;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];

    int nottake = f(coins, ind - 1, target, dp);
    int take = INT_MAX;
    if (coins[ind] <= target)
        take = 1 + f(coins, ind, target - coins[ind], dp);

    return dp[ind][target] = min(nottake, take);
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    // int ans =  f(coins, n, amount, dp);
    // if(ans>=INT_MAX) return -1;
    // return ans;
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            dp[0][i] = i / coins[0];
        else
            dp[0][i] = 1e9;
    }

    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= amount; target++)
        {
            int nottake = dp[i - 1][target];
            int take = 1e9;
            if (coins[i] <= target)
                take = 1 + dp[i][target - coins[i]];
            dp[i][target] = min(nottake, take);
        }
    }
    if (dp[n - 1][amount] >= 1e9)
        return -1;
    return dp[n - 1][amount];
}

int main()
{

    return 0;
}