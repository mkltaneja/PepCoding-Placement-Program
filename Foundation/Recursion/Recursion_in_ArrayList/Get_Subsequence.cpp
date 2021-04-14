#include <iostream>
#include <vector>
using namespace std;

void subsequences(int i, string ans, string &s, vector<string> &ss)
{
    if (i == s.size())
    {
        ss.push_back(ans);
        return;
    }
    subsequences(i + 1, ans, s, ss);
    subsequences(i + 1, ans + s[i], s, ss);
}

int main()
{
    string s;
    cin >> s;
    vector<string> ss;
    subsequences(0, "", s, ss);

    cout << "[";
    for (int i = 0; i < ss.size() - 1; i++)
        cout << ss[i] << ", ";
    cout << ss[ss.size() - 1] << "]";
}

// OR
// Return type of Vector<string>

#include <iostream>
#include <vector>
using namespace std;

vector<string> subsequences(string s)
{
    if (s.size() == 0)
        return {""};

    char c = s[0];
    string nxt = s.substr(1);
    vector<string> ss = subsequences(nxt);

    vector<string> ans;
    for (int i = 0; i < ss.size(); i++)
        ans.push_back("" + ss[i]);
    for (int i = 0; i < ss.size(); i++)
        ans.push_back(c + ss[i]);
    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<string> ss = subsequences(s);

    cout << "[";
    for (int i = 0; i < ss.size() - 1; i++)
        cout << ss[i] << ", ";
    cout << ss[ss.size() - 1] << "]";
}