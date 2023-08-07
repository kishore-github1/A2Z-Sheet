#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    int ans = INT32_MAX;
    int index = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[low] <= nums[mid])
        {
            int temp = ans;
            ans = min(ans, nums[low]);
            if (temp != ans)
                index = low;

            low = mid + 1;
        }
        else
        {
            int temp = ans;
            ans = min(ans, nums[mid]);
            if (temp != ans)
                index = mid;
            high = mid - 1;
        }
    }
    return index;
}

int main()
{
    vector<int> nums = {2, 3, 4, 1};
    cout << findKRotation(nums);

    return 0;
}