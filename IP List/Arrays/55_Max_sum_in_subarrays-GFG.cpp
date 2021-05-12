
long long pairWithMaxSum(long long arr[], long long N)
{
    long long ans = 0;
    for (int i = 0; i < N - 1; i++)
    {
        long long sm = min(arr[i], arr[i + 1]);
        long long ssm = max(arr[i], arr[i + 1]);
        ans = max(ans, ssm + sm);
    }
    return ans;
}