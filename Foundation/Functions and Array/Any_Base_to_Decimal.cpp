#include <iostream>
#include <algorithm>
using namespace std;

int basetodec(int n, int b)
{
    int ans = 0, p = 1;
    while (n)
    {
        ans += (n % 10) * p;
        p *= b;
        n /= 10;
    }

    return ans;
}

int main()
{
    int n, b;
    cin >> n >> b;

    cout << basetodec(n, b);
}