#include <iostream>
using namespace std;

void inc_dec(int a, int n)
{
    if (a == 0)
        return;

    cout << a << endl;
    inc_dec(a - 1, n);
    cout << a << endl;
}

int main()
{
    int n;
    cin >> n;
    inc_dec(n, n);
}