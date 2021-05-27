#include <iostream>
#include <vector>
using namespace std;

void Z_Algorithm(string &str, string &pat, vector<int> &ans)
{
    string s = pat + "#" + str;

    vector<int> zarr(s.size(), 0);
    int l = 0, r = 0;

    for (int i = 1; i < s.size(); i++)
    {
        if (i <= r)
            zarr[i] = min(r - i + 1, zarr[i - l]);
        while (i + zarr[i] < s.size() && s[i + zarr[i]] == s[zarr[i]])
            zarr[i]++;
        if (i + zarr[i] - 1 > r)
        {
            l = i;
            r = i + zarr[i] - 1;
        }

        if (zarr[i] == pat.size())
            ans.push_back(i - pat.size() - 1);
    }
}

int main()
{
    string str, pat;
    cin >> str >> pat;
    vector<int> ans;
    Z_Algorithm(str, pat, ans);

    for (int x : ans)
        cout << x << endl;
    cout << endl;
}