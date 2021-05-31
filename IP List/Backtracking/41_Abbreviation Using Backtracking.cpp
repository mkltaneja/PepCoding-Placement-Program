#include <iostream>
using namespace std;

void abbreviations(int i, int x, string ssf, string &s)
{
    if (i == s.size())
    {
        if (x)
            cout << ssf << x << "\n";
        else
            cout << ssf << "\n";
        return;
    }

    if (x)
        abbreviations(i + 1, 0, ssf + to_string(x) + s[i], s);
    else
        abbreviations(i + 1, 0, ssf + s[i], s);

    abbreviations(i + 1, x + 1, ssf, s);
}

int main()
{
    string s;
    cin >> s;
    abbreviations(0, 0, "", s);
}