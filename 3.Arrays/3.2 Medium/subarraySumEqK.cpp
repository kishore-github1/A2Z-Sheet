#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> preSum;
    int sum = 0;
    preSum[0] = 1;
    int count =0;
    for (auto i : nums)
    {
        sum += i;
        if(preSum.find(sum-k)!=preSum.end()){
            count +=preSum[sum-k];
        }
        preSum[sum]++;
    }
    return count;
}

int main()
{
    vector<int> nums = {1, 1, 1,2};
    int k = 3;
    cout << subarraySum(nums, k);
    return 0;
}