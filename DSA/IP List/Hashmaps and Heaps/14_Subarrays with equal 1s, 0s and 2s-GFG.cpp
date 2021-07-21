long long getSubstringWithEqual012(string str)
{
    int n = str.size();
    int c0 = 0, c1 = 0, c2 = 0;
    map<pair<int, int>, int> m;
    m[{0, 0}] = 1;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0')
            c0++;
        else if (str[i] == '1')
            c1++;
        else
            c2++;

        ans += m[{c0 - c1, c1 - c2}]++;
    }
    return ans;
}