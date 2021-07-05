#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findidx(vector<int> &a, int n, int x)
{
    int st = 0, end = n, idx = 0;
    while (st <= end)
    {
        int mid = (st + end) / 2;
        if (a[mid] < x)
        {
            idx = mid + 1;
            st = mid + 1;
        }
        else if (a[mid] > x)
        {
            idx = mid;
            end = mid - 1;
        }
        else
            return mid;
    }
    return idx;
}

void merge(int n, int m, vector<int> &a, vector<int> &b)
{
    for (int j = 0; j < m; j++)
    {
        int idx = findidx(a, a.size(), b[j]);
        // cout<<idx<<" "<<a.size()<<endl;
        if (idx > a.size())
            a.insert(a.end(), b[j]);
        else
            a.insert(a.begin() + idx, b[j]);
    }

    for (int x : a)
        cout << x << " ";
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    merge(n, m, a, b);
}