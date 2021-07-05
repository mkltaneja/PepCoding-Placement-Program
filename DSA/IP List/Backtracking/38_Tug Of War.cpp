#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findDiff(vector<int> &a, vector<int> &b)
{
    int diff = 0;
    int x = 0, y = 0;
    for (int ele : a)
        x += ele;
    for (int ele : b)
        y += ele;
    return abs(x - y);
}

void tugofwar(int idx, int i, int j, int n, vector<int> &arr, vector<int> &t1, vector<int> &t2, vector<int> &a, vector<int> &b, int &mindiff)
{
    if (idx == n)
    {
        int diff = findDiff(t1, t2);
        if (diff < mindiff)
        {
            mindiff = diff;
            a = t1, b = t2;
        }
        return;
    }
    if (i < t1.size())
    {
        t1[i] = arr[idx];
        tugofwar(idx + 1, i + 1, j, n, arr, t1, t2, a, b, mindiff);
        t1[i] = 0;
    }
    if (j < t2.size())
    {
        t2[j] = arr[idx];
        tugofwar(idx + 1, i, j + 1, n, arr, t1, t2, a, b, mindiff);
        t2[j] = 0;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int mindiff = INT_MAX, ans = 0;
    vector<int> a((n + 1) / 2, 0), b(n / 2, 0), t1((n + 1) / 2, 0), t2(n / 2, 0);

    if (n == 1)
        cout << "-1\n";
    else
        tugofwar(0, 0, 0, n, arr, t1, t2, a, b, mindiff);

    cout << "[";
    for (int i = 0; i < a.size() - 1; i++)
        cout << a[i] << ", ";
    cout << a[a.size() - 1] << "] ";
    cout << "[";
    for (int i = 0; i < b.size() - 1; i++)
        cout << b[i] << ", ";
    cout << b[b.size() - 1] << "]\n";
}