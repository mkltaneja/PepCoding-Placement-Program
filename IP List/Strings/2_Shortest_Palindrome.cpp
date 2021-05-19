#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string kmp = s;
    string rev = s;
    reverse(rev.begin(), rev.end());
    kmp += "#" + rev;

    vector<int> lps(kmp.size());
    int i = 1, len = 0;
    while (i < kmp.size())
    {
        if (kmp[i] == kmp[len])
            lps[i++] = ++len;
        else
        {
            if (len == 0)
                i++;
            else
                len = lps[len - 1];
        }
    }
    string rest = s.substr(len);
    reverse(rest.begin(), rest.end());
    string ans = rest + s;

    cout << ans << endl;
}