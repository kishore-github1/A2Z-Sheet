#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int, int>, int>> q;
    int vis[n][m];
    int intialCnt = 0;
    for (int i = 0; i < n; i++)
    {   
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                vis[i][j] = 2;
                q.push({{i, j}, 0});
            }
            else
            {
                vis[i][j] = 0;
            }
            if (grid[i][j] == 1)
                intialCnt++;
        }
    }

    int arow[] = {1, 0, -1, 0};
    int acol[] = {0, 1, 0, -1};
    int tm=0;
    int finalCnt=0;
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm,t);
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = r+arow[i];
            int ncol = c+acol[i];
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && vis[nrow][ncol]==0 &&grid[nrow][ncol]==1 ){
                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol]=2;
                finalCnt++;
            }
        }
        
    }
    if(intialCnt!=finalCnt) return -1;
    else return tm;
}

int main()
{

    return 0;
}