#include <iostream>
#include <vector>
using namespace std;

void word_selection(int selected, int k, string &s, vector<bool> &vis, string ans)
{
    if (selected == k)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            word_selection(selected + 1, k, s, vis, ans + s[i]);
            vis[i] = false;
        }
    }
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
    vector<bool> vis2(s.size(), false);
    word_selection(0, k, ss, vis2, "");
}