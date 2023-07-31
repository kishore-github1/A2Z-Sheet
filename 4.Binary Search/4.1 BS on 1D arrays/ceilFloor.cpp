#include <bits/stdc++.h>
using namespace std;

int FindFloor(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    int floor = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= x)
        {
            floor = arr[mid];
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return floor;
}
int FindCeil(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    int Ceil = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            Ceil = arr[mid];
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return Ceil;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    int floor = FindFloor(arr, n, x);
    int Ceil = FindCeil(arr, n, x);
    return make_pair(floor,Ceil);
}

int main()
{

    return 0;
}