#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans =n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (target == nums[mid])
            return mid;
        else if (target >= nums[mid])
        {
            
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1,3,5,6};
    int target = 0;
    cout<<searchInsert(nums,target);

    return 0;
}