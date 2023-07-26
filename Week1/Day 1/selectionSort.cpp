#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int mini =arr[i];
        int minpos =i;
        for (int j = i; j < arr.size(); j++)
        {
            if(mini > arr[j]) {
                mini=arr[j];
                minpos = j;
            }
        }
        swap(arr[i],arr[minpos]);
        cout<<arr[i]<<endl;
        
    }
    
}

int main()
{
    vector<int> arr={1,5,6,3,7};
    selectionSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}