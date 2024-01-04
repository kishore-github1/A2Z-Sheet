#include <bits/stdc++.h>
using namespace std;

// Memoization
int f(int i, vector<int> height, vector<int> &dp)
{
    if (i == 0)
        return 0;

    if (dp[i] != -1)
        return dp[i];
    int left = f(i - 1, height, dp) + abs(height[i] - height[i - 1]);
    int ryt = INT16_MAX;
    if (i > 1)
        ryt = f(i - 2, height, dp) + abs(height[i] - height[i - 2]);
    dp[i] = min(left, ryt);
    return dp[i];
}

int minimumEnergy(vector<int> &height, int n)
{
    // Tabulation
    int prev1 = 0 , prev2 = 0 , curr;
    for (int i = 1; i < n; i++)
    {
        int left = prev1 + abs(height[i] - height[i - 1]);
        int ryt = INT_MAX;
        if (i > 1)
            ryt = prev2 + abs(height[i] - height[i - 2]);
        curr = min(left,ryt);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main()
{
    vector<int> height = {10, 20, 30, 10};
    int n = 4;
    cout << minimumEnergy(height, n - 1);

    return 0;
}