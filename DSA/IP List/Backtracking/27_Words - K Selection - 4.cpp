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

    int used = 0;
    for (int i = idx; i < s.size(); i++)
    {
        if (!(used & (1 << s[i] - 'a')))
        {
            used ^= (1 << s[i] - 'a');
            word_selection(i + 1, k, s, ans + s[i]);
        }
    }
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
    string sss = "";
    for (char c : ss)
        while (cnt[c - 'a']--)
            sss += c;
    word_selection(0, k, sss, "");
}