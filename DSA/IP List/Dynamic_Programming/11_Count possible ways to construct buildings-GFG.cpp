
int TotalWays(int N)
{
    int mod = (int)(1e9 + 7);
    long long cb = 1, cs = 1;
    for(int i = 2; i <= N; i++)
    {
        long long tmp = cs;
        cs = (cs % mod + cb % mod) % mod;
        cb = tmp % mod;
    }
    long long ans = (cs % mod + cb % mod) % mod;
    return ((ans % mod) * (ans % mod) + mod) % mod;
}