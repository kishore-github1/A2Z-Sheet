#include <bits/stdc++.h>
using namespace std;

int f(vector<int> coins, int ind, int target, vector<vector<int>> dp)
{
    if (ind == 0)
    {
        if (target % coins[0] == 0)
            return 1;
        else
            return 0;
    }

    if (dp[ind][target] != -1)
        return dp[ind][target];

    int nottake = f(coins, ind - 1, target, dp);
    int take = 0;
    if (coins[ind] <= target)
        take = f(coins, ind, target - coins[ind], dp);

    return dp[ind][target] = nottake + take;
}

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    // return f(coins, n - 1, amount, dp);

    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    for (int i = 0; i < amount + 1; i++)
    {
        if (i % coins[0] == 0)
            dp[0][i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target < amount + 1; target++)
        {
            int nottake = dp[i - 1][target];
            int take = 0;
            if (coins[i] <= target)
                take = dp[i][target - coins[i]];
            dp[i][target] = nottake + take;
        }
    }
    return dp[n - 1][amount];
}

int main()
{
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    cout << change(amount, coins);

    return 0;
}