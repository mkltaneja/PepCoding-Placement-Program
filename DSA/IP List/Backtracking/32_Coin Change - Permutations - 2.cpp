#include <iostream>
#include <vector>
using namespace std;

void coin_change(int tar, int n, vector<int> &coins, vector<bool> &vis, string ans)
{
    if (tar == 0)
    {
        cout << ans + '.' << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (tar - coins[i] >= 0 && !vis[i])
        {
            vis[i] = true;
            coin_change(tar - coins[i], n, coins, vis, ans + to_string(coins[i]) + '-');
            vis[i] = false;
        }
    }
}

int main()
{
    int n, tar;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    cin >> tar;
    vector<bool> vis(n, false);
    coin_change(tar, n, coins, vis, "");
}