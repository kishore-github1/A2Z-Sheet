#include <bits/stdc++.h>
using namespace std;

int minimumEnergy(vector<int> &height, int n, int k)
{
    // Tabulation
    vector<int> dp(n, 0);

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
                mini = min((dp[i-j] + abs(height[i] - height[i-j])), mini);
        }
        dp[i] = mini;
    }
    return dp[n - 1];
}

int main()
{
    vector<int> height = {30, 10, 60, 10, 60, 50};
    int n = 6;
    int k = 2;
    cout << minimumEnergy(height, n , k);

    return 0;
}