#include <iostream>
#include <vector>
using namespace std;

void combination(int idx, int placed, int n, int k, string ans)
{
    if (idx == n)
    {
        if (placed == k)
            cout << ans << endl;
        return;
    }
    combination(idx + 1, placed + 1, n, k, ans + "i");
    combination(idx + 1, placed, n, k, ans + "-");
}

int main()
{
    int n, k;
    cin >> n >> k;
    combination(0, 0, n, k, "");
}