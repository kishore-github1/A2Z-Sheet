#include <bits/stdc++.h>
using namespace std;


void recursion(int open, int close, int n, vector<string> &ans, string s)
{
    if (open == n && close == n)
    {
        ans.push_back(s);
        return;
    }
    if (open < n)
    {
        recursion(open + 1, close, n, ans, s + "(");
    }
    if (open > close)
    {
        recursion(open, close + 1, n, ans, s + ")");
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans = {};
    int open = 0, close = 0;
    string s = "";
    recursion(open, close, n, ans, s);
    return ans;
}

int main()
{

    return 0;
}