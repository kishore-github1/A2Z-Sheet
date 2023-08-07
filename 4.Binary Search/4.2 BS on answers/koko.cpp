#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int> &piles, int h)
{
    int n = piles.size();
    int maxi = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, piles[i]);
    }

    int low = 1, high = maxi;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            int temp = ceil((double)piles[i] / (double)mid);
            sum += temp;
        }
        if (sum <= h)
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
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << minEatingSpeed(piles, h);

    return 0;
}