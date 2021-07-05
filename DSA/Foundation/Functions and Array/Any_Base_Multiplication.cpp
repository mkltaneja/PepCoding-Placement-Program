#include <iostream>
#include <algorithm>
using namespace std;

int base_addition(int n, int m, int b)
{
    int ans = 0, carry = 0, p = 1;

    while (n > 0 || m > 0 || carry > 0)
    {
        int sum = (m % 10) + (n % 10) + carry;
        ans += (sum % b) * p;
        carry = sum / b;
        p *= 10;
        n /= 10;
        m /= 10;
    }
    return ans;
}

int base_multiplication_singledigit(int n, int m, int b)
{
    int ans = 0, p = 1, carry = 0;
    while (n > 0 || carry > 0)
    {
        int prod = ((n % 10) * m) + carry;
        ans += (prod % b) * p;
        carry = prod / b;
        p *= 10;
        n /= 10;
    }
    return ans;
}

int main()
{
    int b, n, m;
    cin >> b >> n >> m;

    int ans = 0, p = 1;
    while (m)
    {
        int prod = base_multiplication_singledigit(n, m % 10, b) * p;
        p *= 10;
        ans = base_addition(ans, prod, b);
        m /= 10;
    }
    cout << ans;
}