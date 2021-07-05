#include <iostream>
using namespace std;

void increasing(int a, int n)
{
    if (a == n + 1)
        return;

    cout << a << endl;
    increasing(a + 1, n);
}

int main()
{
    int n;
    cin >> n;
    increasing(1, n);
}