
int maxEnvelopes(vector<vector<int>>& envelopes) 
{
    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(), [](const auto &a, const auto &b){
        return a[0] == b[0]? a[1] > b[1] : a[0] < b[0];
    });
    
    vector<int> dp(n);
    int maxlen = 0;
    for(vector<int> v : envelopes)
    {
        int l = 0, h = maxlen;
        while(l < h)
        {
            int m = l + (h-l)/2;
            if(dp[m] < v[1])
                l = m + 1;
            else h = m;
        }
        dp[l] = v[1];
        if(l == maxlen) maxlen++;
    }
    return maxlen;
}