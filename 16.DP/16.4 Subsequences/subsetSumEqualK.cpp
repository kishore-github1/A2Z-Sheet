#include <bits/stdc++.h>
using namespace std;

bool subsetSumEqualK(vector<int> &arr, int target, int i)
{
    if (target == 0)
        return true;
    if (i == 0)
        return (arr[0] == target);

    bool notTake = subsetSumEqualK(arr, target, i - 1);
    bool take = false;
    if (arr[i] <= target)
        take = subsetSumEqualK(arr, target - arr[i], i - 1);

    return notTake | take;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int target = 4;
    int n = arr.size();

    //{ind,target}
    vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int t = 1; t <= target; t++)
        {
            bool notTake = dp[i - 1][t];
            bool take = false;
            if(arr[i]<=t) take = dp[i - 1][t - arr[i]];
            dp[i][t] = notTake | take;
        }
    }

    cout << dp[n-1][target];

    // cout << subsetSumEqualK(arr, target, arr.size());

    return 0;
}