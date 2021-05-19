#include <iostream>
#include <vector>
using namespace std;

void permutation(string &s, string ans, vector<bool> &vis)
{
    if (ans.size() == s.size())
    {
        cout << ans << endl;
        return;
    }
    int done = 0;
    for (int j = 0; j < s.size(); j++)
    {
        if (!vis[j] && !(done & (1 << (s[j] - 'a'))))
        {
            vis[j] = true;
            done ^= (1 << (s[j] - 'a'));
            permutation(s, ans + s[j], vis);
            vis[j] = false;
        }
    }
}

int main()
{
    string s;
    cin >> s;
    vector<bool> vis(s.size(), false);
    permutation(s, "", vis);
}