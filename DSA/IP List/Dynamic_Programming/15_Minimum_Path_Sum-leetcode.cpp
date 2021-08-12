
int dfs(int i, int j, int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if(i == n || j == m) return INT_MAX;
    if(dp[i][j] != -1) return dp[i][j];
    if(i == n-1 && j == m-1) return dp[i][j] = arr[i][j];
    
    int d = dfs(i+1, j, n, m, arr, dp);
    int r = dfs(i, j+1, n, m, arr, dp);
    
    return dp[i][j] = arr[i][j] + min(d, r);
}

int minPathSum(vector<vector<int>>& grid) 
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return dfs(0, 0, n, m, grid, dp);
}