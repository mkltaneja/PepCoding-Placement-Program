#include <iostream>
using namespace std;

long int countzeros(long int n)
{
    long int count = 0;
    while (n != 1)
    {
        count++;
        n /= 2;
    }
    return count;
}

long int C(long int n, long int r)
{
    if (n < r)
        return 0;
    if (n == r || n == 1)
        return 1;

    r = min(r, n - r);
    long int ans = 1, i = 0;
    while (i < r)
    {
        ans *= n - i;
        ans /= ++i;
    }

    return ans;
}

int main()
{
    long int n;
    cin >> n;

    long int ans = 0, ones = 1;
    while (n)
    {
        long int rsb = (n & -n);
        long int zeros = countzeros(rsb);
        ans += C(zeros, ones++);
        n -= rsb;
    }
    cout << ans;

    return 0;
}