
long long subCount(long long arr[], int N, long long K)
{
    vector<long long> ps(N);
    for (int i = 0; i < N; i++)
    {
        ps[i] = arr[i] + (i ? ps[i - 1] : 0);
        ps[i] = (ps[i] % K + K) % K;
    }
    long long ans = 0;
    unordered_map<int, long long> m;
    m[0]++;
    for (int i = 0; i < N; i++)
        ans += m[ps[i]]++;
    return ans;
}