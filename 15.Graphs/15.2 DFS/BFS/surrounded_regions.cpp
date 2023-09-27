#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &vis, int n, int m, vector<vector<char>> board,int arow[],int acol[])
{
    vis[row][col] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + arow[i];
        int ncol = col + acol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O')
            dfs(nrow, ncol, vis, n, m, board,arow,acol);
    }
}
void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    int arow[] = {1, 0, -1, 0};
    int acol[] = {0, 1, 0, -1};
    vector<vector<int>> vis(n, vector<int>(m, 0));
    // traverse first row and last row
    for (int j = 0; j < m; j++)
    {
        if (!vis[0][j] && board[0][j] == 'O')
            dfs(0, j, vis, n, m, board,arow,acol);

        if (!vis[n - 1][j] && board[n - 1][j] == 'O')
            dfs(n - 1, j, vis, n, m, board,arow,acol);
    }
    // traverse first column and last column
    for (int i = 0; i < n; i++)
    {
        if (!vis[i][0] && board[i][0] == 'O')
            dfs(i, 0, vis, n, m, board,arow,acol);
        if (!vis[i][m - 1] && board[i][m - 1] == 'O')
            dfs(i, m - 1, vis, n, m, board,arow,acol);
    }
    // traverse all cells
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (!vis[i][j] && board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
}

int main()
{

    return 0;
}