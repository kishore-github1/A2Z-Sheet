#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> res;
    int n = matrix.size();
    int m = matrix[0].size();

    int top = 0, left = 0, right = m - 1, bottom = n - 1;
    while (top <= bottom && left <= right)
    {
       
        for (int i = left; i <= right; i++)
        {
            res.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
            res.push_back(matrix[i][right]);
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >=top; i--)
            {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = spiralOrder(matrix);
    for (auto i : ans)
        cout << i << " ";

    return 0;
}