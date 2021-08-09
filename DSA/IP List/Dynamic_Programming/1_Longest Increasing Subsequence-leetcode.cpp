
// APPROACH 1 --> O(n^2)

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);

    int maxlen = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
        maxlen = max(maxlen, dp[i]);
    }
    return maxlen;
}

// APPROACH 2 --> O(n*logn)

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n);

    int maxlen = 0;
    for (int x : nums)
    {
        int l = 0, h = maxlen;
        while (l < h)
        {
            int mid = l + (h - l) / 2;
            if (dp[mid] < x)
                l = mid + 1;
            else
                h = mid;
        }
        dp[l] = x;
        if (l == maxlen)
            maxlen++;
    }
    return maxlen;
}