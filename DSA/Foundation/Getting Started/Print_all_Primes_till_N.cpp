#include <iostream>
using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int l, h;
    cin >> l >> h;

    for (int n = l; n <= h; n++)
    {
        if (isPrime(n))
            cout << n << endl;
    }

    return 0;
}