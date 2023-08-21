#include <bits/stdc++.h>
using namespace std;

void solution(vector<string> &ans, string &v, int ind, string digits, string mapping[])
{

    if (ind >= digits.length())
    {
        ans.push_back(v);
        return;
    }

    int number = digits[ind] - '0';
    string characters = mapping[number];

    for (int i = 0; i < characters.length(); i++)
    {
        v.push_back(characters[i]);
        solution(ans, v, ind + 1, digits, mapping);
        v.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    if (digits.length() == 0)
        return {};
    vector<string> ans;
    string v;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solution(ans, v, 0, digits, mapping);
    return ans;
}

int main()
{

    return 0;
}