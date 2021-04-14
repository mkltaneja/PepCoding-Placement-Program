#include <iostream>
#include <algorithm>
using namespace std;

int base_addition(int n, int m, int b)
{
    int ans = 0, carry = 0, p = 1;

    while (n > 0 || m > 0 || carry > 0)
    {
        int sum = (n % 10) + (m % 10) + carry;
        ans += (sum % b) * p;
        p *= 10;
        carry = sum / b;
        n /= 10;
        m /= 10;
    }
    return ans;
}

int main()
{
    int b, n, m;
    cin >> b >> n >> m;

    cout << base_addition(n, m, b);
}