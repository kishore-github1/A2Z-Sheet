#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n)
{
    if(n==1) return;
        for (int j = 0; j < n-1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    bubbleSort(arr,n-1);
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