#include <iostream>
#include <vector>
using namespace std;

void word_selection(int idx, int selected, int k, string &s, vector<char> &ans)
{
    if (idx == s.size())
    {
        if (selected == k)
        {
            for (char c : ans)
                cout << c;
            cout << endl;
        }
        return;
    }
    int used = 0;

    for (int i = 0; i < k; i++)
    {
        if (ans[i] == NULL)
        {
            ans[i] = s[idx];
            word_selection(idx + 1, selected + 1, k, s, ans);
            ans[i] = NULL;
        }
    }
    word_selection(idx + 1, selected, k, s, ans);
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
    vector<char> ans(k, false);
    word_selection(0, 0, k, ss, ans);
}