
// O(N*K) Approach

int minCostII(vector<vector<int>> &costs)
{
    int n = costs.size();
    if (n == 0)
        return 0;
    int k = costs[0].size();
    vector<vector<int>> dp = costs;
    for (int i = 1; i < n; i++)
    {
        int mn = INT_MAX, mn2 = INT_MAX;
        for (int j = 0; j < k; j++)
        {
            if (dp[i - 1][j] < mn)
            {
                mn2 = mn;
                mn = dp[i - 1][j];
            }
            else
                mn2 = min(mn2, dp[i - 1][j]);
        }
        for (int j = 0; j < k; j++)
        {
            if (dp[i - 1][j] == mn)
                dp[i][j] += mn2;
            else
                dp[i][j] += mn;
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < k; i++)
        ans = min(ans, dp[n - 1][i]);

    return ans;
}