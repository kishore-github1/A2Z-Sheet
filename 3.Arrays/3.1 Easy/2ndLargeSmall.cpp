#include <bits/stdc++.h>
using namespace std;

int small(vector<int> a)
{
    int smallest = INT16_MAX;
    int smaller = INT16_MAX;
    for (auto i : a)
    {
        if (i < smallest)
        {
            smaller = smallest;
            smallest = i;
        }
        else if (i < smaller && i > smallest)
            smaller = i;
    }
    
    if(smaller==INT16_MAX) return -1;
    return smaller;
}
int large(vector<int> a)
{
    int largest = INT16_MIN;
    int larger = INT16_MIN;
    for (auto i : a)
    {
        if (i > largest)
        {
            larger = largest;
            largest = i;
        }
        else if (i > larger && i < largest)
            larger = i;
    }
    if(larger==INT16_MIN) return -1;
    return larger;
}

vector<int> getSecondOrderElements(int n, vector<int> a)
{
    vector<int> ans;
    
    ans.push_back(large(a));
    ans.push_back(small(a));
    
    return ans;
}

int main()
{
    int n = 4;
    vector<int> a = {3,4,5,2};
    vector<int> ans = getSecondOrderElements(n, a);
    for (auto i : ans)
        cout << i << " ";

    return 0;
}