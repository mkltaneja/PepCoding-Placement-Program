#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void merge(int n, int m, vector<int> &a, vector<int> &b)
{
    vector<int> c(n + m);
    int i = 0, j = 0, k = 0;
    while (i < n || j < m)
    {
        int x, y;
        if (i >= n)
            x = INT_MAX;
        else
            x = a[i];
        if (j >= m)
            y = INT_MAX;
        else
            y = b[j];
        if (x < y)
            c[k++] = x, i++;
        else
            c[k++] = y, j++;
    }

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
    merge(n, m, a, b);
}