
int lcs3(int i, int j, int k, int l, int m, int n, string &a, string &b, string &c, vector<vector<vector<int>>> &dp)
{
    if (i == l || j == m || k == n)
        return 0;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];
    int ans = 0;
    if (a[i] == b[j] && b[j] == c[k])
        ans = lcs3(i + 1, j + 1, k + 1, l, m, n, a, b, c, dp) + 1;
    else
    {
        int x = lcs3(i + 1, j, k, l, m, n, a, b, c, dp);
        int y = lcs3(i, j + 1, k, l, m, n, a, b, c, dp);
        int z = lcs3(i, j, k + 1, l, m, n, a, b, c, dp);
        ans = max(x, max(y, z));
    }
    return dp[i][j][k] = ans;
}

int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    vector<vector<vector<int>>> dp(n1, vector<vector<int>>(n2, vector<int>(n3, -1)));
    return lcs3(0, 0, 0, n1, n2, n3, A, B, C, dp);
    // your code here
}