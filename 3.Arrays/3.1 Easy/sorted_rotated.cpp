#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n-1; i++)
    {
        if(nums[i]>nums[i+1]) count++;
    }
    if(nums[n-1]>nums[0]) count++;
    if(count>1) return false;
    return true;
    
}

int main()
{
    vector<int> nums = {2,1,3,4};
    bool ans=check(nums);
    cout<<ans;

    return 0;
}