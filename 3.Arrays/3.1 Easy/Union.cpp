#include <bits/stdc++.h>
using namespace std;

vector<int> sortedArray(vector<int> a, vector<int> b)
{
    int n = a.size();
    int m = b.size();
    int i = 0, j = 0;
    vector<int> res;
    while (i < n && j < m)
    {

        if (a[i] <= b[j])
        {
            if (res.size() == 0 || res.back() != a[i])
            {
                res.push_back(a[i]);
            }
            i++;
        }

        else
        {
            if (res.size() == 0 || res.back() != b[j])
            {
                res.push_back(b[j]);
            }
            j++;
        }
    }
    while (i < n)
    {
        if (res.size() == 0 || res.back() != a[i])
        {
            res.push_back(a[i]);
        }
        i++;
    }
    while (j < m)
    {
        if (res.size() == 0 || res.back() != b[j])
        {

            res.push_back(b[j]);
        }
        j++;
    }
    return res;
}
int main()
{
    vector<int> a = {3, 4, 5, 6};
    vector<int> b = {1, 2, 3, 4};
    vector<int> ans = sortedArray(a, b);
    for (auto i : ans)
        cout << i << " ";

    return 0;
}