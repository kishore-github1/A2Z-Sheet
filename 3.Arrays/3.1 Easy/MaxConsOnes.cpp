#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int count = 0;
    int maxCount = 0 ;
    for (int i = 0; i < nums.size(); i++)
    {
       if(nums[i]==1) count++;
       else count = 0;
       maxCount=max(count,maxCount); 
    }
    return maxCount;
    
}

int main()
{
    vector<int> nums = {1,0,1,1,0,1};
    cout<<findMaxConsecutiveOnes(nums)<<endl;

    return 0;
}