#include <bits/stdc++.h>
using namespace std;

void solution(vector<vector<int>> &ans, vector<int> &v, int ind, int target, vector<int> candidates)
{
    if (target == 0)
    {
        ans.push_back(v);
        return;
    }
    for (int i = ind; i < candidates.size(); i++)
    {
        if (target<candidates[i])
            break;
        if (i > ind && candidates[i] == candidates[i - 1])
            continue;
        v.push_back(candidates[i]);
        solution(ans, v, ind + 1, target - candidates[i], candidates);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    vector<int> v;
    solution(ans,v,0,target,candidates);
    return ans;
}

int main()
{

    return 0;
}