#include <bits/stdc++.h>
using namespace std;

// int posInd(int temp, vector<int> nums)
// {
//     for (int i = temp + 1; i < nums.size(); i++)
//     {
//         if (nums[i] > 0)
//             return i;
//     }
//     return -1;
// }

// int negInd(int temp, vector<int> nums)
// {
//     for (int i = temp + 1; i < nums.size(); i++)
//     {
//         if (nums[i] < 0)
//             return i;
//     }
//     return -1;
// }

// vector<int> rearrangeArray(vector<int> nums)
// {
//     vector<int> ans;
//     int PrevPosInd = posInd(-1, nums);
//     int PrevNegInd = -1;
//     ans.push_back(nums[PrevPosInd]);
//     while (ans.size() != nums.size())
//     {
//         if (ans.back() < 0)
//         {
//             int temp = PrevPosInd;
//             PrevPosInd = posInd(temp, nums);
//             ans.push_back(nums[PrevPosInd]);
//         }
//         else if (ans.back() > 0)
//         {
//             int temp = PrevNegInd;
//             PrevNegInd = negInd(temp, nums);
//             ans.push_back(nums[PrevNegInd]);
//         }
//     }
//     return ans;
// }

vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> ans(nums.size(), 0);
    int posInd = 0, negInd = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            ans[posInd] = nums[i];
            posInd += 2;
        }
        else
        {
            ans[negInd] = nums[i];
            negInd += 2;
        }
    }
    return ans;
}

int main()
{

    vector<int> nums = {3, 2, 1, -1, -2, -3};
    vector<int> ans = rearrangeArray(nums);
    for (auto i : ans)
        cout << i << " ";

    return 0;
}