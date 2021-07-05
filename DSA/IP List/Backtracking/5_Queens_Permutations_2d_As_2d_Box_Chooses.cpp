#include <iostream>
#include <vector>
using namespace std;

void permutation2D(int idx, int placed, int n, vector<bool> items, vector<vector<int>> box, string ans)
{
    if (idx == n * n)
    {
        if (placed == n)
            cout << ans << "\n\n";
        return;
    }

    int r = idx / n, c = idx % n;
    char last = (c == n - 1) ? '\n' : '\t';

    for (int x = 1; x <= n; x++)
    {
        if (items[x] == false)
        {
            items[x] = true;
            permutation2D(idx + 1, placed + 1, n, items, box, ans + "q" + to_string(x) + last);
            items[x] = false;
        }
    }
    permutation2D(idx + 1, placed, n, items, box, ans + "-" + last);
}

int main()
{
    int n;
    cin >> n;
    vector<bool> items(n + 1, false);
    vector<vector<int>> box(n, vector<int>(n, 0));
    permutation2D(0, 0, n, items, box, "");
}