#include <iostream>
#include <vector>
using namespace std;

void fill_palindrome(int n, string &s, vector<vector<bool>> &dp)
{
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = true;
                continue;
            }
            if (s[i] == s[j])
                if (gap == 1 || dp[i + 1][j - 1])
                    dp[i][j] = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        string temp = "";
        for (int j = i; j < n; j++)
        {
            temp += s[j];
            if (dp[i][j])
                cout << temp << endl;
        }
    }
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    fill_palindrome(n, s, dp);
}