#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int> &nums)
{
    int Xor = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        Xor ^= nums[i];
    }
    return Xor;
}

int main()
{

    return 0;
}