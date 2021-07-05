#include <iostream>
#include <vector>
using namespace std;

void word_selection(int idx, int k, string &s, vector<int> &cnt, string ans)
{
    if (idx == s.size())
    {
        if (ans.size() == k)
            cout << ans << endl;
        return;
    }

    for (int i = cnt[s[idx] - 'a']; i > 0; i--)
    {
        int x = i;
        string tmp = "";
        while (x--)
            tmp += s[idx];
        word_selection(idx + 1, k, s, cnt, ans + tmp);
    }
    word_selection(idx + 1, k, s, cnt, ans);
}

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;

    vector<int> cnt(26, 0);
    string ss = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (!cnt[s[i] - 'a'])
            ss += s[i];
        cnt[s[i] - 'a']++;
    }
    // cout<<ss<<endl;
    word_selection(0, k, ss, cnt, "");
}