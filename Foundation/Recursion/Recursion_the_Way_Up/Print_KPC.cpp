#include <iostream>
#include <vector>
using namespace std;

void get_kpc(int i, string ans, string &s, vector<string> &keypad)
{
    if (i == s.size())
    {
        cout << ans << endl;
        return;
    }

    for (char c : keypad[s[i] - '0'])
        get_kpc(i + 1, ans + c, s, keypad);
}

int main()
{
    string s;
    cin >> s;
    vector<string> keypad = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
    get_kpc(0, "", s, keypad);
}