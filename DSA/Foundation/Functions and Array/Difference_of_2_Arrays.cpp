#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void arraydiff(int n, int m, vector<int> &a, vector<int> &b)
{
    vector<int> c(m);
    int carry = 0;

    int i = n - 1, j = m - 1, k = m - 1;
    while (k >= 0)
    {
        int x = (i >= 0) ? a[i] : 0;
        if (b[j] + carry >= x)
        {
            c[k] = (b[j] + carry) - x;
            carry = 0;
        }
        else
        {
            c[k] = (b[j] + carry + 10) - x;
            carry = -1;
        }
        i--, j--, k--;
    }
    while (c[k] == 0)
        k++;

    for (; k < m; k++)
        cout << c[k] << endl;
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

    arraydiff(n, m, a, b);
}