#include <bits/stdc++.h>
using namespace std;

// int f(int arr[], int sum, int ind, vector<vector<int>> &dp)
// {
//     if (sum == 0)
//         return 1;
//     if (ind == 0)
//         return (arr[ind] == sum);

//     if (dp[ind][sum] != -1)
//         return dp[ind][sum];

//     int notTake = f(arr, sum, ind - 1, dp);
//     int take = 0;
//     if (arr[ind] <= sum)
//         take = f(arr, sum - arr[ind], ind - 1, dp);
//     dp[ind][sum] = notTake + take;
//     return dp[ind][sum];
// }
int perfectSum(int arr[], int n, int sum)
{
    // vector<vector<int>> dp(n, vector<int>(sum+1, -1));
    // return f(arr, sum, n - 1, dp);
    // vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    vector<int> prev(sum + 1, 0);
    prev[0] = 1;
    if (arr[0] <= sum)
        prev[arr[0]] = 1;

    // for (int i = 0; i < n; i++)
    //     dp[i][0] = 1;
    // if (arr[0] <= sum)
    //     dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(sum + 1, 0);
        curr[0] = 1;
        for (int s = 1; s <= sum; s++)
        {
            int notTake = prev[s];
            int take = 0;
            if (arr[i] <= s)
                take = prev[s - arr[i]];

            curr[s] = notTake + take;
        }
        prev = curr;
    }
    return prev[sum];
}

int main()
{
    int arr[] = {9, 7, 0, 3, 9, 8, 6, 5, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 31;
    cout << perfectSum(arr, n, sum);

    return 0;
}