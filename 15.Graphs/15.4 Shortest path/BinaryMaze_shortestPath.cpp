#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    if(grid[0][0]==1) return -1;
   
    int n = grid.size();
     if(n-1 == 0) return 1;
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    dist[0][0] = 0;
    // {dist,{i,j}}
    queue<pair<int, pair<int, int>>> q;
    q.push({1, {0, 0}});

    while (!q.empty())
    {
        pair<int,pair<int,int>> node = q.front();
        int dis = node.first;
        int orow = node.second.first;
        int ocol = node.second.second;
        q.pop();

        int nrow[] = {-1, -1, -1, 0, +1, +1, +1, 0};
        int ncol[] = {-1, 0, +1, +1, +1, 0, -1, -1};

        for (int i = 0; i < 8; i++)
        {
            int row = orow + nrow[i];
            int col = ocol + ncol[i];

            if (row < n && col < n && row >= 0 && col >= 0 && grid[row][col] == 0)
            {
                if (dis + 1 < dist[row][col])
                {
                    dist[row][col] = dis + 1;
                    q.push({dist[row][col], {row, col}});
                    if (row == n - 1 && col == n - 1)
                        return dist[row][col];
                }
            }
        }
    }
    return -1;
}

int main()
{

    return 0;
}