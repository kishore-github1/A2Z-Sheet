#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr,int i, int size)
{
    if(i==size) return;
        for (int j = i; j > 0; j--)
        {
            if(arr[j]<arr[j-1]) swap(arr[j],arr[j-1]);
            else break;
        }
        
    insertionSort(arr,i+1,size);
    
}

int main()
{
    int size= 5;
     vector<int> arr={3,7,8,1,2};
   insertionSort(arr,0,size);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}