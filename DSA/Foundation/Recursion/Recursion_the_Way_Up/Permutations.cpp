#include <iostream>
#include <vector>
using namespace std;

void permutations(string ans, string &s, vector<bool> &vis)
{
    if (ans.size() == s.size())
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            permutations(ans + s[i], s, vis);
            vis[i] = false;
        }
    }
}

int main()
{
    string s;
    cin >> s;
    vector<bool> vis(s.size(), false);
    permutations("", s, vis);
}