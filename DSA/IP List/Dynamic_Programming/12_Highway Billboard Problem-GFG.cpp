#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> x(n), rev(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> rev[i];
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
        map[x[i]] = rev[i];

    int t;
    cin >> t;

    vector<int> dp(m + 1, 0);

    dp[0] = map[0];
    for (int i = 1; i <= m; i++)
        dp[i] = ((i-t-1 >= 0) ? max(dp[i-t-1] + map[i], dp[i - 1]) : max(dp[i - 1], map[i]));
    cout << dp[m] << endl;

    return 0;
}