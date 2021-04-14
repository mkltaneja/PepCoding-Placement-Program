#include <iostream>
using namespace std;

void string_compression(int n, string &s)
{
    int i = 0;
    string c1 = "", c2 = "";
    while (i < n)
    {
        char c = s[i];
        int count = 0;
        while (s[i] == c)
            count++, i++;
        c1 += c;
        c2 += c;
        if (count != 1)
            c2 += to_string(count);
    }
    cout << c1 << endl
         << c2;
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    string_compression(n, s);
}