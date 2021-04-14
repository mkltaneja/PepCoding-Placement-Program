#include <iostream>
#include <string>
using namespace std;

void ASCII_diff(string &s)
{
    string ans = "";
    ans += s[0];
    for (int i = 1; i < s.size(); i++)
    {
        int diff = s[i] - s[i - 1];
        ans += to_string(diff) + s[i];
    }
    cout << ans;
}

int main()
{
    string s;
    cin >> s;

    ASCII_diff(s);
}