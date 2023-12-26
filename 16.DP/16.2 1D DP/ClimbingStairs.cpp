#include <bits/stdc++.h>
using namespace std;

int recur(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int left = recur(n - 1, dp) ;
    int ryt = recur(n - 2, dp);
    dp[n] = left + ryt;
    return dp[n];
}

int climbStairs(int n)
{

    vector<int> dp(n + 1, -1);
    return recur(n, dp);
}

int main()
{
    int n = 45;
    cout << climbStairs(n);

    return 0;
}