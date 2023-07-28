#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int count = 0, element = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
            element = nums[i];
        if (element == nums[i])
            count++;
        else
            count--;
    }
    return element;
}

int main()
{

    return 0;
}