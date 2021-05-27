
// APPROACH 1 (Brute Force Backtracking)

#include <iostream>
#include <vector>
using namespace std;

string maxans = "";
void kswaps(string &s, int k)
{
    if (maxans.empty() || s > maxans)
        maxans = s;
    if (k == 0)
        return;

    for (int i = 0; i < s.size() - 1; i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[j] > s[i])
            {
                swap(s[i], s[j]);
                kswaps(s, k - 1);
                swap(s[i], s[j]);
            }
        }
    }
}

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    string ms = s;
    kswaps(s, k);
    cout << maxans << endl;
}


