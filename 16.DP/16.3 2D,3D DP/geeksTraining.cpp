#include <bits/stdc++.h>
using namespace std;

int f(vector<vector<int>> points, int day, int last, vector<vector<int>> &dp)
{
    if (dp[day][last] != -1)
        return dp[day][last];
    int n = points.size();
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        return dp[0][last] = maxi;
    }
    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        int pts = 0;
        if (task != last)
        {
            pts = points[day][task] + f(points, day - 1, task, dp);
        }
        maxi = max(maxi, pts);
    }
    return dp[day][last] = maxi;
}
int maximumPoints(vector<vector<int>> &points, int n)
{
    // vector<vector<int>> dp(n, vector<int>(4, 0));

    // // Tabulation

    // dp[0][0] = max(points[0][1], points[0][2]);
    // dp[0][1] = max(points[0][0], points[0][1]);
    // dp[0][2] = max(points[0][1], points[0][3]);
    // dp[0][3] = max(points[0][1], max(points[0][2], points[0][0]));

    // space optimization
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][1], points[0][0]);
    prev[3] = max(points[0][1], max(points[0][2], points[0][0]));

    for (int day = 1; day < n; day++)
    {
        vector<int> pres(4,0);
        for (int last = 0; last < 4; last++)
        {
            int activity;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    activity = points[day][task] + prev[task];
                    pres[last] = max(pres[last], activity);
                }
            }
        }
        prev = pres;
    }
    return prev[3];

    // return f(points, n - 1, 3, dp);
}

int main()
{
    int n = 3;
    vector<vector<int>> point = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    cout << "Maximum Points: " << maximumPoints(point, n);

    return 0;
}