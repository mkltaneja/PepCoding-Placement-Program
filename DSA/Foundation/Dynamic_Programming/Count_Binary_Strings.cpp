
// METHOD 1 (Recursive)
#include <iostream>
using namespace std;

int generate_binary(int i, int x, int n)
{
    if (i == n)
        return 1;
    if (x == 0)
        return generate_binary(i + 1, 1, n);
    else
        return generate_binary(i + 1, 0, n) + generate_binary(i + 1, 1, n);
}

int main()
{
    int n;
    cin >> n;
    cout << generate_binary(0, 1, n) << endl;
}

// METHOD 2 (OPTIMIZED Using DP Memoization)
#include <iostream>
#include <vector>
using namespace std;

int generate_binary(int i, int x, int n, vector<vector<int>> &dp)
{
    if (i == n)
        return 1;
    if (dp[i][x] != -1)
        return dp[i][x];
    if (x == 0)
        return generate_binary(i + 1, 1, n, dp);
    else
        return generate_binary(i + 1, 0, n, dp) + generate_binary(i + 1, 1, n, dp);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << generate_binary(0, 1, n, dp) << endl;
}

// METHOD 3 (Tabulated)
#include <iostream>
#include <vector>
using namespace std;

int generate_binary(int i, int x, int n, vector<vector<int>> &dp)
{
    dp[n][0] = 1;
    dp[n][1] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i][0] = dp[i + 1][1];
        dp[i][1] = dp[i + 1][0] + dp[i + 1][1];
    }
    return dp[i][1];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(2));
    cout << generate_binary(0, 1, n, dp) << endl;
}