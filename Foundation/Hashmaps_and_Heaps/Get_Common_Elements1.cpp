#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, bool> avl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        avl[a[i]] = true;
    }
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    for (int x : b)
    {
        if (avl[x])
        {
            cout << x << endl;
            avl[x] = false;
        }
    }
}