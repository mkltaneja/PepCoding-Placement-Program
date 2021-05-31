#include <iostream>
#include <vector>
using namespace std;

void display(string &pat, vector<string> &code)
{
    vector<bool> vis(26, false);
    for (char c : pat)
    {
        if (!vis[c - 'a'])
        {
            vis[c - 'a'] = true;
            cout << c << " -> " << code[c - 'a'] << ", ";
        }
    }
    cout << ". \n";
}

void pattern_matching(int idx, int i, string &str, string &pat, vector<string> &code)
{
    if (idx == pat.size())
    {
        if (i == str.size())
            display(pat, code);
        return;
    }

    string curr = code[pat[idx] - 'a'];
    if (!curr.empty())
    {
        if (str.substr(i).size() >= curr.size() && curr == str.substr(i, curr.size()))
            pattern_matching(idx + 1, i + curr.size(), str, pat, code);
        else
            return;
    }
    else
    {
        string s = "";
        for (int j = i; j < str.size(); j++)
        {
            s += str[j];
            code[pat[idx] - 'a'] = s;
            // cout<<pat[idx]<<" -> "<<s<<endl;
            pattern_matching(idx + 1, j + 1, str, pat, code);
            code[pat[idx] - 'a'] = curr;
        }
    }
}

int main()
{
    string str, pat;
    cin >> str >> pat;
    vector<string> code(26, "");
    pattern_matching(0, 0, str, pat, code);
}