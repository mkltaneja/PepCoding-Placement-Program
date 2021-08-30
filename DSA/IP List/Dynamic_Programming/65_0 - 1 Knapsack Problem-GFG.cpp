
    int knapSack01(int W, int wt[], int val[], int n, vector<vector<int>> &dp)
    {
        if(n == 0) return 0;
        if(dp[n-1][W] != -1) return dp[n-1][W];
        
        if(W < wt[n-1])
            return dp[n-1][W] = knapSack01(W, wt, val, n-1, dp);
        else
            return dp[n-1][W] = max(val[n-1] + knapSack01(W-wt[n-1], wt, val, n-1, dp), knapSack01(W, wt, val, n-1, dp));
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    {
        vector<vector<int>> dp(n, vector<int>(W+1,-1));
        return knapSack01(W, wt, val, n, dp);
    }