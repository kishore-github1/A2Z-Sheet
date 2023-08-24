#include <bits/stdc++.h>
using namespace std;



vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> v;
    if(root==NULL) return v;
    int flag =0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {

        int n = q.size();
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {

            TreeNode *front = q.front();
            q.pop();
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);

            temp.push_back(front->val);
        }
        if (flag == 0)
            flag = 1;
        else
            flag = 0;
        if (flag == 0)
        {
            reverse(temp.begin(), temp.end());
        }
        v.push_back(temp);
    }
    return v;
}

int main()
{

    return 0;
}