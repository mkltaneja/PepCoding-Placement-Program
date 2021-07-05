
// NOTE1:- Difference between Euclid and Extended Euclid theoerm is that Euclid theorem is just to find GCD, but extended Euclid can also solve the linear equation (a*x + b*y = gcd(a, b))
// NOTE2:- Also in Extended Euclid x and y are the multiplicative inverses of a and b, iff a and b are co-prime(gcd(a, b) == 1). So with this property we can find multiplicative inverse of a and b.
#include <bits/stdc++.h>
using namespace std;

int extended_euclid(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extended_euclid(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

int gcd(int N, vector<int> &arr)
{
    int ans = arr[0];
    for (int i = 1; i < N; i++)
    {
        int x, y;
        ans = extended_euclid(arr[i], ans, x, y);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << gcd(n, a) << "\n";
}