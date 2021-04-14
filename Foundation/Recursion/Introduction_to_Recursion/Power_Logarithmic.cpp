#include <iostream>
using namespace std;

int power_log(int x, int n)
{
    if (n == 0)
        return 1;

    int call = power_log(x, n / 2);
    int xn = call * call;

    if (n & 1)
        return x * xn;
    else
        return xn;
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << power_log(x, n);
}