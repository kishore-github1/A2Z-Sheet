#include <bits/stdc++.h>
using namespace std;
int sol(vector<int> nums)
{
    int prev1 = nums[0], prev2 = 0, n = nums.size();
    for (int i = 1; i < n; i++)
    {
        int p = nums[i];
        if (i > 1)
            p += prev2;
        int np = prev1;
        int curr = max(p, np);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(nums[i]);
        if (i != n - 1)
            temp2.push_back(nums[i]);
    }
    return max(sol(temp1), sol(temp2));
}
int main()
{

    return 0;
}