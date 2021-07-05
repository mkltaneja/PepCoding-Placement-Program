#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> fmap;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        fmap[a[i]]++;
    }
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        if (fmap[b[i]])
            cout << b[i] << endl;
        fmap[b[i]]--;
    }

    return 0;
}