#include <bits/stdc++.h>
using namespace std;

int minDays(vector<int> &bloomDay, int m, int k)
{
    int low = INT32_MAX, high = INT32_MIN;
    int n = bloomDay.size();
    if (n < m * k)
        return -1;
    for (int i = 0; i < n; i++)
    {
        low = min(low, bloomDay[i]);
        high = max(high, bloomDay[i]);
    }
   
    int mid=0, ans = 0;;
    while (low <= high)
    {
        int count = 0, boquets = 0;
         mid = (low + high) / 2;
   
        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= mid)
            {
                count++;
            }
            else
            {
                boquets += count / k;
                count = 0;
            }
        }
       
        boquets += count / k;

       
        if (boquets >= m)
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
    vector<int> bloomsday ={7,7,7,7,12,7,7};
    int m = 2;
    int k = 3;
    cout<<minDays(bloomsday,m,k);

    return 0;
}