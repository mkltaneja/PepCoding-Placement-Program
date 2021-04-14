#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int nst = 1, nsp = 2 * n - 3;
    for (int i = 1; i <= n; i++)
    {
        for (int cst = 1; cst <= nst; cst++)
            cout << cst << "\t";
        for (int csp = 1; csp <= nsp; csp++)
            cout << "\t";
        for (int cst = (i == n) ? nst - 1 : nst; cst >= 1; cst--)
            cout << cst << "\t";
        cout << endl;
        nsp -= 2;
        nst++;
    }

    return 0;
}