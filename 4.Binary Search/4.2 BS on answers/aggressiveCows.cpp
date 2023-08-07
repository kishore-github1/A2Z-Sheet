#include <bits/stdc++.h>
using namespace std;

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    if(n<k) return -1;
    int low=1,high=0;
    int maxi=INT16_MIN,mini=INT16_MAX;
    for (auto i : stalls){
        maxi = max(maxi,i);
        mini = min(mini,i); 
    }
    high = maxi-mini;

    while(low<=high){
        int mid = (low+high)/2;

        int countCows=1, last = stalls[0];
        for (int i = 1; i < n; i++)
        {
            if(stalls[i]-last>=mid){
                countCows++;
                last = stalls[i];
            }
        }
        if(countCows>=k) low=mid+1;
        else high = mid-1;
    }
    return high;

}

int main()
{

    return 0;
}