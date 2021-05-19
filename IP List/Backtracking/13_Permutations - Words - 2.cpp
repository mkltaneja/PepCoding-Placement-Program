#include <iostream>
#include <vector>
using namespace std;

void permutation(int i, int placed, string &s, vector<char> &ans, vector<int> &lastocc)
{
    if (placed == s.size())
    {
        for (char c : ans)
            cout << c;
        cout << endl;
        return;
    }
    int lo = lastocc[s[i] - 'a'];
    for (int j = lo + 1; j < ans.size(); j++)
    {
        if (ans[j] == NULL)
        {
            ans[j] = s[i];
            lastocc[s[i] - 'a'] = j;
            permutation(i + 1, placed + 1, s, ans, lastocc);
            ans[j] = NULL;
            lastocc[s[i] - 'a'] = lo;
        }
    }
}

int main()
{
    string s;
    cin >> s;
    vector<int> lastocc(26, -1);
    vector<char> ans(s.size());
    permutation(0, 0, s, ans, lastocc);
}