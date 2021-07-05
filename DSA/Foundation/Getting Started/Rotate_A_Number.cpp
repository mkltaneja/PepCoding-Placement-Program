#include <iostream>
#include <math.h>
using namespace std;

int rotate_number(int n, int k)
{
    int count = 0, temp = n;
    while (temp)
    {
        count++;
        temp /= 10;
    }

    k %= count;
    if (k < 0)
        k += count;

    int rem = pow(10, k);
    int a = n % rem;
    int b = n / rem;
    int x = pow(10, count - k);
    a *= x;
    a += b;
    // cout<<b<<endl;
    return a;
}

int main()
{
    int n, k;
    cin >> n >> k;

    cout << rotate_number(n, k);
}