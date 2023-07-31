#include <bits/stdc++.h>
using namespace std;

int findFirst(vector<int> arr, int n, int target)
{
    int low = 0, high = n - 1;
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return ans;
}

int findSecond(vector<int> arr, int n, int target)
{
    int low = 0, high = n - 1;
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return ans;
}

int count(vector<int> &arr, int n, int x)
{
    int first = findFirst(arr, n, x);
    int second = findSecond(arr, n, x);
    if(!first && !second) return 0;
    return second - first + 1;
}

int main()
{

    return 0;
}