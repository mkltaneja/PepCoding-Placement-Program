#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(int n, int m, vector<int> &a, vector<int> &b)
{
    int i = 0, j = 0, k = 0;
    vector<int> c(n + m);
    while (i < n && j < m)
    {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while (i < n)
        c[k++] = a[i++];
    while (j < m)
        c[k++] = b[j++];

    return c;
}

vector<int> merge_sort(int st, int end, vector<int> &a)
{
    if (st == end)
        return {a[st]};
    int mid = (st + end) >> 1;
    vector<int> l = merge_sort(st, mid, a);
    vector<int> r = merge_sort(mid + 1, end, a);

    cout << "Merging these two arrays \n";

    cout << "left array -> ";
    for (int x : l)
        cout << x << " ";
    cout << endl;
    cout << "right array -> ";
    for (int x : r)
        cout << x << " ";
    cout << endl;

    return merge(l.size(), r.size(), l, r);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> ans = merge_sort(0, n - 1, a);
    cout << "Sorted Array -> ";
    for (int x : ans)
        cout << x << " ";
}