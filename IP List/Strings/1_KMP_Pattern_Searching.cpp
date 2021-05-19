#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string str, pat;
    cin >> str >> pat;

    string s = pat + "#" + str;

    vector<int> lps(s.size(), 0);
    vector<int> ans;
    int i = 1, len = 0;
    while (i < s.size())
    {
        if (s[i] == s[len])
        {
            lps[i++] = ++len;
            if (len == pat.size())
                ans.push_back(i - len - (pat.size() + 1));
        }
        else
        {
            if (len == 0)
                i++;
            else
                len = lps[len - 1];
        }
    }

    for (int x : ans)
        cout << x << endl;
}