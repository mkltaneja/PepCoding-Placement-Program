#include <iostream>
#include <vector>
using namespace std;

void combination2D(int idx, int n, int placed, string ans)
{
    if (idx == n * n)
    {
        if (placed == n)
            cout << ans << "\n";
        return;
    }
    int c = idx % n;
    string yesans = (c == n - 1) ? "q\n" : "q";
    string noans = (c == n - 1) ? "-\n" : "-";
    combination2D(idx + 1, n, placed + 1, ans + yesans);
    combination2D(idx + 1, n, placed, ans + noans);
}

int main()
{
    int n;
    cin >> n;
    combination2D(0, n, 0, "");
}