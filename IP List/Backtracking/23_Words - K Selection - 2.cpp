#include <iostream>
#include <vector>
using namespace std;

void word_selection(int idx, int k, string &s, string ans)
{
    if (ans.size() == k)
    {
        cout << ans << endl;
        return;
    }

    for (int i = idx; i < s.size(); i++)
        word_selection(i + 1, k, s, ans + s[i]);
}

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;

    vector<bool> vis(26, false);
    string ss = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (!vis[s[i] - 'a'])
        {
            vis[s[i] - 'a'] = true;
            ss += s[i];
        }
    }
    word_selection(0, k, ss, "");
}