
int sortingCost(int N, int arr[])
{
    unordered_map<int, int> m;
    for (int i = 0; i < N; i++)
        m[arr[i]] += m[arr[i] - 1] + 1;
    int mxcom = 0;
    for (auto p : m)
        mxcom = max(mxcom, p.second);
    return (N - mxcom);
}