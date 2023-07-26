#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int left = 0;
    int right = 0;
    int sum = 0;
    int ans = 0;

    while (right < a.size())
    {
        while (left <= right && sum > k)
        {
            sum -= a[left];
            left++;
        }
        if (sum == k)
            ans = max(ans, right - left + 1);
        right++;
        if (right < a.size())
            sum += a[right];
    }
    return ans;
}

int main()
{
    vector<int> a = {1, 2, 1, 3};
    int k = 2;
    cout << longestSubarrayWithSumK(a, k);
    return 0;
}