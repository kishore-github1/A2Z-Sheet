#include <bits/stdc++.h>
using namespace std;

void solution(vector<int> &ans, vector<int> nums, int sum, int ind)
{
    if (ind == nums.size())
    {
        ans.push_back(sum);
        return;
    }
    sum += nums[ind];
    solution(ans, nums, sum, ind + 1);
    sum -= nums[ind];
    solution(ans, nums, sum, ind + 1);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    solution(ans, num, 0, 0);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}