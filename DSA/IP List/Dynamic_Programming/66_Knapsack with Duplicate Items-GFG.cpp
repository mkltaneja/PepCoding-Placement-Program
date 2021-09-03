
int knapsack_unbound(int N, int W, int val[], int wt[], vector<vector<int>> &dp)
{
    if (N == 0)
        return 0;
    if (dp[N - 1][W] != -1)
        return dp[N - 1][W];

    if (wt[N - 1] > W)
        return dp[N - 1][W] = knapsack_unbound(N - 1, W, val, wt, dp);
    else
        return dp[N - 1][W] = max(val[N - 1] + knapsack_unbound(N, W - wt[N - 1], val, wt, dp), knapsack_unbound(N - 1, W, val, wt, dp));
}

int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(N, vector<int>(W + 1, -1));
    return knapsack_unbound(N, W, val, wt, dp);
}