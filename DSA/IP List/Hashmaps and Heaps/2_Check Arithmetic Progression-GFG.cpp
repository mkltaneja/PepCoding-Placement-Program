
bool checkIsAP(int arr[], int n)
{
    unordered_map<int, int> m;
    int mn = INT_MAX, mn2 = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        if (x < mn)
        {
            mn2 = mn;
            mn = x;
        }
        else
            mn2 = min(mn2, x);
        m[x]++;
    }
    int d = mn2 - mn;
    while (m.count(mn))
    {
        if (--m[mn] == 0)
            m.erase(mn);
        mn += d;
    }
    return m.empty();
}