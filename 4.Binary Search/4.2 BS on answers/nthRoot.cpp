#include <bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m)
{
    int low = 1, high = m;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long val=1;
        for(int i = 0; i < n; i++)
             val *= mid;

        if (val <= (long long)n)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return high;
}

int main()
{

    return 0;
}