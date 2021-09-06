
int maxHeight(int height[], int width[], int length[], int n)
{
    vector<vector<int>> box(3 * n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        box[3 * i] = {length[i], min(height[i], width[i]), max(height[i], width[i])};
        box[3 * i + 1] = {width[i], min(height[i], length[i]), max(height[i], length[i])};
        box[3 * i + 2] = {height[i], min(length[i], width[i]), max(length[i], width[i])};
    }
    sort(box.begin(), box.end(), [](vector<int> &a, vector<int> &b)
         { return (a[1] == b[1]) ? (a[2] > b[2]) : (a[1] < b[1]); });

    vector<int> dp(3 * n);
    int maxans = 0;
    for (int i = 0; i < 3 * n; i++)
    {
        dp[i] = box[i][0];
        for (int j = i - 1; j >= 0; j--)
            if (box[j][2] < box[i][2] && dp[j] + box[i][0] > dp[i])
                dp[i] = dp[j] + box[i][0];
        maxans = max(maxans, dp[i]);
    }
    return maxans;
}