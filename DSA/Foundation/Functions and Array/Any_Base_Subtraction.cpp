#include <iostream>
#include <algorithm>
using namespace std;

int base_subtraction(int n, int m, int b)
{
    int ans = 0, carry = 0, p = 1;

    while (n > 0 || m > 0)
    {
        int diff;
        if (((m % 10) + carry) >= (n % 10))
        {
            diff = ((m % 10) + carry) - (n % 10);
            carry = 0;
        }
        else
        {
            diff = ((m % 10) + carry + b) - (n % 10);
            carry = -1;
        }
        ans += diff * p;
        p *= 10;
        n /= 10;
        m /= 10;
    }
    return ans;
}

int main()
{
    int b, n, m;
    cin >> b >> n >> m;

    cout << base_subtraction(n, m, b);
}