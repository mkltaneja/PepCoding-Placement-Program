#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void maxconsec(vector<int> &a)
{
    unordered_map<int, int> m;
    int maxlen = 0;
    int st = -1, end = -1;
    for (int i = 0; i < a.size(); i++)
    {
        int x = a[i];
        if (m[x])
            continue;
        int sn = x - m[x - 1], en = x + m[x + 1];
        int len = m[sn] + m[en] + 1;
        if (m[x - 1] && m[x + 1])
        {
            m[x] = len;
            m[sn] = len;
            m[en] = len;
        }
        else if (m[x - 1])
        {
            m[x] = len;
            m[sn] = len;
        }
        else if (m[x + 1])
        {
            m[x] = len;
            m[en] = len;
        }
        else
            m[x] = len;
        if (len > maxlen)
        {
            maxlen = len;
            st = sn;
            end = en;
        }
    }
    // cout<<maxlen<<endl;
    for (int i = st; i <= end; i++)
        cout << i << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n > 0)
        maxconsec(a);

    return 0;
}