#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nsp1 = n / 2, nsp2 = -1;
    for (int i = 0; i < n; i++)
    {
        for (int csp = 1; csp <= nsp1; csp++)
            cout << "\t";
        cout << "*\t";
        for (int csp = 1; csp <= nsp2; csp++)
            cout << "\t";
        if (i != 0 && i != n - 1)
            cout << "*\t";
        cout << endl;

        if (i < n / 2)
            nsp1--, nsp2 += 2;
        else
            nsp1++, nsp2 -= 2;
    }
    return 0;
}