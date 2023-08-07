#include <bits/stdc++.h>
using namespace std;

int findPages(vector<int> &arr, int n, int m)
{
    if (m>n)
        return -1;

    int low = 0, high = 0;
    for (auto i : arr)
    {
        low = max(low, i);
        high += i;
    }
    if (m == n)
        return low;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int countStudents = 0, pages = 0;
        for (auto i : arr)
        {
            if (pages + i <= mid)
            {
                pages += i;
            }
            else
            {
                countStudents++;
                pages = i;
            }
        }
        if (countStudents >= m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{

    return 0;
}