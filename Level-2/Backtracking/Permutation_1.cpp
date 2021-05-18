#include <iostream>
#include <vector>
using namespace std;

void permutation(int x, int n, int k, vector<int> items)
{
    if (x == k + 1)
    {
        for (int x : items)
            cout << x;
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (items[i] == 0)
        {
            items[i] = x;
            permutation(x + 1, n, k, items);
            items[i] = 0;
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> items(n, 0);
    permutation(1, n, k, items);
}