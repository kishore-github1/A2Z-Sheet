#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int smallest = INT16_MAX, maxProfit = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < smallest)
        {
            smallest = prices[i];
        }
        if (prices[i] - smallest > maxProfit)
            maxProfit = prices[i] - smallest;
    }
    return maxProfit;
}

int main()
{

    return 0;
}