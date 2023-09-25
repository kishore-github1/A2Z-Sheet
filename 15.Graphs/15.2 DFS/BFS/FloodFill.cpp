#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int n = image.size();
    int m = image[0].size();
    queue<pair<int, int>> q;
    q.push({sr, sc});

    vector<vector<int>> vis(n,vector<int>(m,0));
    vis[sr][sc] = 1;
    if (image[sr][sc] == color)
        return image;
    int intialColor = image[sr][sc];
    image[sr][sc] = color;
    int arow[] = {1, 0, -1, 0};
    int acol[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + arow[i];
            int ncol = c + acol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && image[nrow][ncol] == intialColor)
            {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
                image[nrow][ncol] = color;
            }
        }
    }
    return image;
}

int main()
{

    return 0;
}