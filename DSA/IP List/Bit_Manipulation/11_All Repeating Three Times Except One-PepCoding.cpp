#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int n3 = (1 << 31) - 1, n3p1 = 0, n3p2 = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp0 = (n3 & arr[i]), tmp1 = (n3p1 & arr[i]), tmp2 = (n3p2 & arr[i]);
        n3 &= ~tmp0;
        n3p1 &= ~tmp1;
        n3p2 &= ~tmp2;
        n3 |= tmp2;
        n3p1 |= tmp0;
        n3p2 |= tmp1;
    }

    cout << n3p1 << endl;
}