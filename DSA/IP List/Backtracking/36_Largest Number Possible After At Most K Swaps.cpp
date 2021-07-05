
// APPROACH 1 (Brute Force Backtracking) --> O((n^2)^k)

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

// APPROACH 2 (Sort the string in decreasing order, and check if current index doesn't match with the maximum char then swap) --> O(n^2) to O(n^n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string maxans = "";
void kswaps(int i, int k, string &s, string &maxs)
{
    if (maxans.empty() || s > maxans)
        maxans = s;
    if (i == s.size() || k == 0)
        return;

    if (s[i] != maxs[i])
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[j] == maxs[i])
            {
                swap(s[i], s[j]);
                kswaps(i + 1, k - 1, s, maxs);
                swap(s[i], s[j]);
            }
        }
    }
    else
        kswaps(i + 1, k, s, maxs);
}

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    string ms = s;
    sort(ms.begin(), ms.end(), greater<char>());
    kswaps(0, k, s, ms);
    cout << maxans << endl;
}