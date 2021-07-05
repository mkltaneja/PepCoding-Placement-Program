#include <iostream>

using namespace std;

void subsequences(int i, string ans, string &s)
{
    if (i == s.size())
    {
        cout << ans << endl;
        return;
    }

    subsequences(i + 1, ans + s[i], s);
    subsequences(i + 1, ans, s);
}

int main()
{
    string s;
    cin >> s;
    subsequences(0, "", s);
}