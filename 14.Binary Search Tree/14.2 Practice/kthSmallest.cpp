#include <bits/stdc++.h>
using namespace std;

void inorder(TreeNode *root, int k, int &ans, int &count)
{
    if(root==NULL) return;

    inorder(root->left,k,ans,count);
    int val = root->val;
    count++;
    if(count==k) {
        ans = val;
        return;
    }
    inorder(root->right,k,ans,count);
    return;
}

int kthSmallest(TreeNode *root, int k)
{
    int ans = root->val;
    int count = 0;
    inorder(root,k,ans,count);
    return ans;

}

int main()
{

    return 0;
}