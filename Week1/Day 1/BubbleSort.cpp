#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main()
{
    int n = 5;
     vector<int> arr={1,5,6,3,7};
    bubbleSort(arr,n);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}