#include <iostream>
using namespace std;

int power_lin(int x, int n)
{
    if (n == 0)
        return 1;

    return x * power_lin(x, n - 1);
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << power_lin(x, n);
}