#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                temp[j] = 0;
                continue;
            }

            if (i == 0 && j == 0)
            {
                temp[j] = 1;
                continue;
            }

            int r = 0, d = 0;
            if (j > 0)
            {
                r = temp[j - 1];
            }

            if (i > 0)
                d = prev[j];
            temp[j] = r + d;
        }
        prev = temp;
    }
    return prev[n - 1];
}

int main()
{
    vector<vector<int>> obstaclegrid ={{0,1},{0,0}};//= {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout<<uniquePathsWithObstacles(obstaclegrid);

    return 0;
}