#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void arraysum(int n, int m, vector<int> &a, vector<int> &b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> c(max(n, m));
    int carry = 0;

    int i = 0;
    for (; i < min(n, m); i++)
    {
        int sum = a[i] + b[i] + carry;
        c[i] = sum % 10;
        carry = sum / 10;
    }
    for (; i < n; i++)
    {
        int sum = a[i] + carry;
        c[i] = sum % 10;
        carry = sum / 10;
    }
    for (; i < m; i++)
    {
        int sum = b[i] + carry;
        c[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry > 0)
        c.push_back(carry);

    reverse(c.begin(), c.end());

    for (int x : c)
        cout << x << endl;
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    arraysum(n, m, a, b);
}