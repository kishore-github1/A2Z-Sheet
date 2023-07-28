#include <bits/stdc++.h>
using namespace std;

vector<int> superiorElements(vector<int> &a)
{
    vector<int> ans;
    int n = a.size();
    int max = 0;
    for (int i = n - 1; i > -1; i--)
    {
        if (a[i] > max)
        {
            max = a[i];
            ans.push_back(a[i]);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{

    return 0;
}