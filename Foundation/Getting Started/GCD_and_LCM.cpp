#include <iostream>
using namespace std;

int GCD(int x, int y)
{
    if (x % y == 0)
        return y;
    return GCD(y, x % y);
}

int main()
{
    int a, b;
    cin >> a >> b;

    int x = max(a, b);
    int y = min(a, b);
    int gcd = GCD(x, y);
    int lcm = (x * y) / gcd;

    cout << gcd << endl
         << lcm << endl;

    return 0;
}