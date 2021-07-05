#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    string s;
    cin >> s;
    unordered_map<char, int> m;
    for (char c : s)
        m[c]++;
    int maxf = 0;
    char maxc = NULL;
    for (auto p : m)
    {
        if (p.second > maxf)
        {
            maxf = p.second;
            maxc = p.first;
        }
    }
    cout << maxc << endl;
}