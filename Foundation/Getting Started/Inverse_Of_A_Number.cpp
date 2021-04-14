#include <iostream>
#include <math.h>
using namespace std;

int inverse(int n)
{
    int inv = 0;
    int i = 1;
    while (n)
    {
        inv += i * pow(10, (n % 10) - 1);
        n /= 10;
        i++;
    }
    return inv;
}

int main()
{
    int n;
    cin >> n;

    cout << inverse(n);

    return 0;
}