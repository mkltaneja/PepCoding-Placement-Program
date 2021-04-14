#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nst = n / 2 + 1, nsp = 1;
    for (int i = 0; i < n; i++)
    {
        for (int cst = 1; cst <= nst; cst++)
            cout << "*\t";
        for (int csp = 1; csp <= nsp; csp++)
            cout << "\t";
        for (int cst = 1; cst <= nst; cst++)
            cout << "*\t";
        cout << endl;
        if (i < n / 2)
            nst--, nsp += 2;
        else
            nst++, nsp -= 2;
    }
    return 0;
}