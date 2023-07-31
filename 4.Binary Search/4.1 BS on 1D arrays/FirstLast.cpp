#include <bits/stdc++.h>
using namespace std;

int findFirst(vector<int> nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return ans;
}

int findSecond(vector<int> nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> res;
    res.push_back(findFirst(nums, target));
    res.push_back(findSecond(nums, target));
    return res;
}

int main()
{

    return 0;
}