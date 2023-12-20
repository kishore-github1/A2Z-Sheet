#include <bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> diff(n, vector<int>(m, 1e9));
    diff[0][0] = 0;
    // {diff,{i,j}}
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});

    int nrow[] = {-1, 0, +1, 0};
    int ncol[] = {0, +1, 0, -1};

    while (!q.empty())
    {
        pair<int, pair<int, int>> node = q.front();
        int dif = node.first;
        int orow = node.second.first;
        int ocol = node.second.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int row = orow + nrow[i];
            int col = ocol + ncol[i];

            if (row < n && col < m && row >= 0 && col >= 0)
            {
                int absdiff = abs(heights[orow][ocol] - heights[row][col]);
                int neweffort = max(absdiff, dif);
                if (neweffort < diff[row][col])
                {
                    diff[row][col] = neweffort;
                    q.push({neweffort, {row, col}});
                }
            }
        }
    }
    return diff[n - 1][m - 1];
}

int main()
{

    return 0;
}