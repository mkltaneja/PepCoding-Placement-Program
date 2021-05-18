#include <iostream>
#include <vector>
using namespace std;

void permutation(int idx, int placed, int n, int k, vector<bool> items, vector<int> box)
{
    if (idx == n)
    {
        if (placed == k)
        {
            for (int x : box)
                cout << x;
            cout << endl;
        }
        return;
    }

    for (int x = 1; x <= k; x++)
    {
        if (items[x] == false)
        {
            box[idx] = x;
            items[x] = true;
            permutation(idx + 1, placed + 1, n, k, items, box);
            box[idx] = 0;
            items[x] = false;
        }
    }
    permutation(idx + 1, placed, n, k, items, box);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<bool> items(k + 1, false);
    vector<int> box(n, 0);
    permutation(0, 0, n, k, items, box);
}