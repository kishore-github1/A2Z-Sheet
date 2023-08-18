#include <bits/stdc++.h>
using namespace std;

    void solution(vector<vector<int>> &ans, int ind, vector<int> &v, vector<int> candidates, int target)
    {
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0 || ind >=candidates.size()){
            return;
        }
        v.push_back(candidates[ind]);
        solution(ans,ind,v,candidates,target-candidates[ind]);
        v.pop_back();
        solution(ans,ind+1,v,candidates,target);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans{};
        vector<int> v{};
        solution(ans, 0, v, candidates, target);
        return ans;
    }

int main()
{

    return 0;
}