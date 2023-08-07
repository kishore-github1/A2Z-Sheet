#include <bits/stdc++.h>
using namespace std;

int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();
    int low = 1, high = 0;
    for (int i = 0; i < n; i++)
    {
        high = max(high, nums[i]);
    }
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += ceil((double)nums[i] / (double)mid);
        }

        if (sum <= threshold)
        {
            ans = mid;

            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 5, 9};
    cout << smallestDivisor(nums, 6);

    return 0;
}