#include <bits/stdc++.h>
using namespace std;

void solution(vector<vector<int>> &ans, vector<int> &v, int ind, int target, int k)
{
    if (target == 0 && v.size() == k)
    {
        ans.push_back(v);
        return;
    }
    if (target < 0 || v.size() > k)
        return;

    for (int i = ind; i <= 9; i++)
    {
        if (target < i)
            break;
        v.push_back(i);
        solution(ans, v, i + 1, target - i, k);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> ans;
    vector<int> v;
    solution(ans, v, 1, n, k);
    return ans;
}

int main()
{

    return 0;
}