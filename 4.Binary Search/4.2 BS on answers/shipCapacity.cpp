#include <bits/stdc++.h>
using namespace std;

int shipWithinDays(vector<int> &weights, int days)
{
    int n = weights.size();
    int low = 0, high = 0;
    for (auto i : weights)
    {
        low = max(low, i);
        high += i;
    }
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int count = 1, sum = 0;
        for (auto weight : weights)
        {
            if (sum + weight > mid)
            {
                sum = weight;
                count++;
            }
            else
            {
                sum += weight;
            }
        }
        if (count <= days)
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
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Ship within Days: " << shipWithinDays(nums, 5) << endl;

    return 0;
}