#include <iostream>
#include <vector>
using namespace std;

void coin_change(int tar, int n, vector<int> &coins, string ans)
{
    if (tar == 0)
    {
        cout << ans + '.' << endl;
        return;
    }
    for (int i = 0; i < n; i++)
        if (tar - coins[i] >= 0)
            coin_change(tar - coins[i], n, coins, ans + to_string(coins[i]) + '-');
}

int main()
{
    int n, tar;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    cin >> tar;
    coin_change(tar, n, coins, "");
}