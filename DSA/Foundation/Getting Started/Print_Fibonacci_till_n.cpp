#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a = 0, b = 0, sum = 1;
    cout << a << endl;
    for (int i = 2; i <= n; i++)
    {
        cout << sum << endl;
        a = b;
        b = sum;
        sum = a + b;
    }

    return 0;
}