#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e9 + 7;

int f(vector<int> nums, int s2)
{
    // if (ind == 0)
    // {
    //     if (target == 0 && target == nums[0])
    //         return 2;
    //     if (target == 0 || target == nums[0])
    //         return 1;
    //     else
    //         return 0;
    // }
    // if (dp[ind][target] != -1)
    //     return dp[ind][target];

    // int nottake = f(nums, ind - 1, target, dp);
    // int take = 0;
    // if (nums[ind] <= target)
    //     take = f(nums, ind - 1, target - nums[ind], dp);

    // return dp[ind][target] = nottake + take;

    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(s2 + 1, 0));

    if (nums[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    if (nums[0] != 0 && nums[0] <= s2)
        dp[0][nums[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int t = 0; t <= s2; t++)
        {
            int nottake = dp[i - 1][t];
            int take = 0;
            if (nums[i] <= t)
                take = dp[i - 1][t - nums[i]];
            dp[i][t] = (nottake + take) % mod;
        }
    }
    return dp[n - 1][s2];
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int tsum = 0;
    for (auto i : nums)
        tsum += i;

    if (tsum - target < 0)
        return 0;
    if ((tsum - target) % 2 != 0)
        return 0;

    int s2 = (tsum - target) / 2;

    // vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));

    // return f(nums, n - 1, s2, dp);

    return f(nums, s2);
}

int main()
{

    vector<int> nums = {1};
    int target = 1;
    cout << findTargetSumWays(nums, target);

    return 0;
}