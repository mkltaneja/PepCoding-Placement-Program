#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a = 0, b = 0, sum = 1;
    cout << a << endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = n - i - 1; j < n; j++)
        {
            cout << sum << "\t";
            a = b;
            b = sum;
            sum = a + b;
        }
        cout << endl;
    }
    return 0;
}