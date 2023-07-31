#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    int ans = INT16_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[low] <= nums[mid])
        {
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans,nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {3,1,2};
    cout<<findMin(nums);

    return 0;
}