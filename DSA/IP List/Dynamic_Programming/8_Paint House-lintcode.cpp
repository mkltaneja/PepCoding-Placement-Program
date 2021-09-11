
// RECURSIVE =====================

int min_cost(int i, int prevc, int n, vector<vector<int>> &costs, vector<vector<int>> &dp)
{
    if (i == n)
        return 0;
    if (dp[i][prevc] != INT_MAX)
        return dp[i][prevc];

    int minc = INT_MAX;
    for (int c = 1; c <= 3; c++)
        if (c != prevc)
            minc = min(minc, min_cost(i + 1, c, n, costs, dp) + costs[i][c - 1]);
    return dp[i][prevc] = minc;
}

int minCost(vector<vector<int>> &costs)
{
    int n = costs.size();
    vector<vector<int>> dp(n + 1, vector<int>(4, INT_MAX));
    return min_cost(0, 0, n, costs, dp);
}



// TABULATED =================

int minCost(vector<vector<int>> &costs)
{
    int n = costs.size();
    vector<vector<int>> dp = costs;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][j] = INT_MAX;
            for (int k = 0; k < 3; k++)
                if (k != j)
                    dp[i][j] = min(dp[i - 1][k], dp[i][j]);
            dp[i][j] += costs[i][j];
        }
    }
    return n ? min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) : 0;
}