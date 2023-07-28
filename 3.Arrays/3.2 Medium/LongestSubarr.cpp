#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int> &nums, int k)
{
    int ans = INT16_MIN, sum = 0;
    int ansStart = 0, ansEnd = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum > ans)
        {
            ans = sum;
            ansEnd = i;
        }
        if (sum < 0)
        {
            sum = 0;
            ansStart = i;
        }
    }
    return ansEnd - ansStart + 1;
}

int main()
{

    return 0;
}