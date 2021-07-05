#include <iostream>
using namespace std;

int is_pythagorean_triplet(int x, int a, int b)
{
    return (a * a + b * b == x * x);
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int x = max(a, max(b, c));
    bool isans;
    if (x == a)
        isans = is_pythagorean_triplet(x, b, c);
    if (x == b)
        isans = is_pythagorean_triplet(x, a, c);
    if (x == c)
        isans = is_pythagorean_triplet(x, a, b);
    cout << (boolalpha) << isans;

    return 0;
}