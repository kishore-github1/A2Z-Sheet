#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (auto i : nums)
        sum += i;
    if (sum % 2 == 1)
        return false;
    int target = sum / 2;

    vector<bool> prev(target + 1, false);
    prev[0] = true;
    if (nums[0] <= target)
        prev[nums[0]] = true;

    for (int i = 1; i < n; i++)
    {
        vector<bool> curr(target + 1, false);
        curr[0] = true;
        for (int t = 1; t <= target; t++)
        {
            bool notTake = prev[t];
            bool take = false;
            if (nums[i] <= t)
                take = prev[t - nums[i]];
            curr[t] = notTake || take;
        }
        prev = curr;
    }
    return prev[target];
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    cout << canPartition(nums);

    return 0;
}