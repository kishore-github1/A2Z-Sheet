#include <bits/stdc++.h>
using namespace std;

void solution(vector<vector<int>> &ans, int ind, vector<int> &v, vector<int> nums)
{
    if (ind == nums.size())
    {
        ans.push_back(v);
        return;
    }
    v.push_back(nums[ind]);
    solution(ans, ind + 1, v, nums);
    v.pop_back();
    solution(ans, ind + 1, v, nums);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> v = {};
    solution(ans, 0, v, nums);
    return ans;
}

int main()
{

    return 0;
}