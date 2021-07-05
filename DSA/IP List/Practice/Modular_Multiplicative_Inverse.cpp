
int extended_euclid(int a, int m, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return m;
    }
    int x1, y1;
    int gcd = extended_euclid(m % a, a, x1, y1);
    x = y1 - (m / a) * x1;
    y = x1;

    return gcd;
}

int modInverse(int a, int m)
{
    int x, y;
    int gcd = extended_euclid(a, m, x, y);
    if (m == 1 || gcd != 1)
        return -1;
    return ((x % m) + m) % m;
}