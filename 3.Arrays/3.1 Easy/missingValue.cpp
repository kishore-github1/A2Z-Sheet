#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    // sort(nums.begin(), nums.end());
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (i != nums[i])
    //         return i;
    // }
    // return nums.size();
    int n = nums.size();
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < n; i++)
    {
        xor1 ^= i;
        xor2 ^= nums[i];
    }
    xor1 ^= n;
    return xor1 ^ xor2;
}

int main()
{

    vector<int> nums = {0, 1};
    cout << missingNumber(nums) << endl;

    return 0;
}