#include <bits/stdc++.h>
using namespace std;

int f(int i, vector<int> nums, vector<int> &dp)
{
    if (i == 0)
        return nums[i];
    if (i < 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int p = nums[i] + f(i - 2, nums, dp);
    int np = f(i - 1, nums, dp);
    dp[i] = max(p, np);
    return dp[i];
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    // vector<int> dp(n, 0);
    // dp[0] = nums[0];
    // for (int i = 1; i < n; i++)
    // {
    //     int p = nums[i];
    //     if (i > 1)
    //         p += dp[i - 2];
    //     int np = dp[i-1];
    //     dp[i] = max(p, np);
    // }
    // return dp[n-1];

    int prev1 = nums[0] , prev2 = 0 ; 
    for (int i = 1; i < n; i++)
    {
        int p = nums[i];
        if(i>1) p+=prev2;
        int np = prev1;
        int curr = max(p,np);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
    
}

int main()
{
    return 0;
}