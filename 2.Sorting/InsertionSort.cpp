#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr, int size)
{
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = i; j > 0; j--)
        {
            if(arr[j]<arr[j-1]) swap(arr[j],arr[j-1]);
            else break;
        }
        
    }
    
}

int main()
{
    int size= 5;
     vector<int> arr={3,7,8,1,2};
   insertionSort(arr,size);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}