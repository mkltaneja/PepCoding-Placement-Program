
vector<int> sieveOfEratosthenes(int n)
{
    vector<int> vis(n + 1, false);
    for (int i = 2; i * i <= n; i++)
    {
        if (vis[i])
            continue;
        for (int j = i * i; j <= n; j += i)
            vis[j] = true;
    }
    vector<int> ans;
    for (int i = 2; i <= n; i++)
        if (!vis[i])
            ans.push_back(i);

    return ans;
}