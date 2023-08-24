#include <bits/stdc++.h>
using namespace std;

int solution(TreeNode *root, int &ans)
{
    if (!root)
        return 0;

    int ls = max(0,solution(root->left,ans));
    int rs = max(0,solution(root->right,ans));

    ans = max(ans, root->val + (ls + rs));

    return root->val + max(ls, rs);
}

int maxPathSum(TreeNode *root)
{
    int ans = INT_MIN;
    solution(root, ans);
    return ans;
}

int main()
{

    return 0;
}