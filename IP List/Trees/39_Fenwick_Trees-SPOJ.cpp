#include <bits/stdc++.h>
using namespace std;

vector<long> fenarr;

void update(int i, int x)
{
    while(i < fenarr.size())
    {
        fenarr[i] += x;
        i += (i & -i);
    }
}

long totsum(int i)
{
    long sum = 0;
    while(i > 0)
    {
        sum += fenarr[i];
        i -= (i & -i);
    }
    return sum;
}

int main()
{
    int n, q;
    cin >> n;
    vector<long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    fenarr.resize(n+1, 0);
    for(int i = 1; i <= n; i++)
        update(i, a[i-1]);

    vector<long> ans;
    cin >> q;
    while (q--)
    {
        char c;
        cin>>c;
        if (c == 'q')
        {
            int l, r;
            cin >> l >> r;
            long sum = totsum(r) - totsum(l-1);
            ans.push_back(sum);
        }
        else
        {
            int i, x;
            cin >> i >> x;
            update(i, x);
        }
    }
    for(long x : ans) cout<<x<<"\n";

    return 0;
}