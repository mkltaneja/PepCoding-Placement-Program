
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    vector<long long> ans(N - K + 1);
    int negi = N;
    for (int i = N - 1; i >= 0; i--)
    {
        if (A[i] < 0)
            negi = i;
        if (i < N - K + 1)
        {
            if (negi < i + K)
                ans[i] = A[negi];
            else
                ans[i] = 0;
        }
    }
    return ans;
}