#include <iostream>
#include <string>
using namespace std;

void toggle_case(string &s)
{
    for (char &c : s)
    {
        if (isupper(c))
            c = tolower(c);
        else
            c = toupper(c);
    }
    cout << s;
}

int main()
{
    string s;
    cin >> s;

    toggle_case(s);
}