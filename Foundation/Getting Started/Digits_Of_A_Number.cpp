#include <iostream>
#include <math.h>
using namespace std;

void digits(int n)
{
    int nn = n, count = 0;
    while (nn)
    {
        count++;
        nn /= 10;
    }
    int m = pow(10, count - 1);

    while (m)
    {
        cout << (n / m) << endl;
        n %= m;
        m /= 10;
    }
}

int main()
{
    int n;
    cin >> n;

    digits(n);

    return 0;
}