
long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    vector<int> c0(n), c1(n);
    unordered_map<int, long long> m;
    m[0] = 1;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            c0[i] = (i ? c0[i - 1] + 1 : 1);
            c1[i] = (i ? c1[i - 1] : 0);
        }
        else
        {
            c1[i] = (i ? c1[i - 1] + 1 : 1);
            c0[i] = (i ? c0[i - 1] : 0);
        }
        ans += m[c0[i] - c1[i]]++;
    }
    return ans;
}