#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    for (i = 0; i < n-1; i++)
    {
        if (nums[i] == 0)
            break;
    }

    for (int j = i+1; j < n; j++)
    {
        if(nums[j]!=0){
            swap(nums[i],nums[j]);
            i++;
        }
    }
    
}

int main()
{
    vector<int> nums = {5, 0, 2, 3, 0, 1};
    moveZeroes(nums);
    for (auto i : nums)
        cout << i << " ";

    return 0;
}