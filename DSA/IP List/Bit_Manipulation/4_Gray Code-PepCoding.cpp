#include <iostream>
#include <vector>
using namespace std;

vector<string> solution(int n)
{
    if (n == 1)
        return {"0", "1"};
    vector<string> prev = solution(n - 1);
    vector<string> curr;
    for (int i = 0; i < prev.size(); i++)
        curr.push_back("0" + prev[i]);
    for (int i = prev.size() - 1; i >= 0; i--)
        curr.push_back("1" + prev[i]);

    return curr;
}

int todec(string &s)
{
    int ans = 0;
    for (char c : s)
        ans = ans * 2 + (c - '0');
    return ans;
}

vector<int> grayCode(int n)
{
    vector<string> bin = solution(n);
    vector<int> ans;
    for (string s : bin)
        ans.push_back(todec(s));
    return ans;
}

int main(int argc, char **argv)
{

    int n;
    cin >> n;
    vector<int> res = grayCode(n);
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "]";
}