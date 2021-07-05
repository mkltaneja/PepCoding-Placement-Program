#include <iostream>
#include <vector>
using namespace std;

vector<string> get_kpc(int i, string &s, vector<string> &keypad)
{
    if (i == s.size())
        return {""};

    vector<string> arr = get_kpc(i + 1, s, keypad);
    vector<string> ans;
    for (char c : keypad[s[i] - '0'])
        for (string a : arr)
            ans.push_back(c + a);
    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<string> keypad = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
    vector<string> ans = get_kpc(0, s, keypad);
    cout << "[";
    for (int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << ", ";
    cout << ans[ans.size() - 1] << "]";
}