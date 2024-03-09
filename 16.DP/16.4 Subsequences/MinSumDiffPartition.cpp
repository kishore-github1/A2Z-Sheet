#include <bits/stdc++.h>
using namespace std;

int minimumDifference(vector<int> &nums)
{
    int n = nums.size();
    if(n==1) return nums[0];
    if(n==2) return abs(nums[0]-nums[1]);
    int target = 0;
    for (auto i : nums)
    {
        target += abs(i);
    }

    vector<bool> prev(target + 1, false);
    prev[0] = true;
    if (abs(nums[0]) <= target)
        prev[nums[0]] = true;

    for (int i = 1; i < n; i++)
    {
        vector<bool> curr(target + 1, false);
        curr[0] = true;

        for (int t = 1; t <= target; t++)
        {
            bool notTake = prev[t];
            bool take = false;
            if (abs(nums[i]) <= t)
                take = prev[t - abs(nums[i])];
            curr[t] = notTake || take;
        }
        swap(prev, curr);
    }
    int mini = 1e9;
    for (int i = 0; i <= target; i++)
    {
        if (prev[i] == true)
        {
            int s1 = i;
            int s2 = target - i;
            mini = min(mini, abs(s1 - s2));
        }
    }

    return mini;
}

int main()
{

    vector<int> nums = {-36, 36};
    cout << minimumDifference(nums);

    return 0;
}