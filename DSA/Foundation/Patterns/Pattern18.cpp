#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int nst = n - 2, nsp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int csp = 1; csp <= nsp; csp++)
            cout << "\t";
        cout << "*\t";
        for (int cst = 1; cst <= nst; cst++)
        {
            if (i == 0 || i > n / 2)
                cout << "*\t";
            else
                cout << "\t";
        }
        if (i != n / 2)
            cout << "*\t";
        cout << endl;

        if (i < n / 2)
            nst -= 2, nsp++;
        else
            nst += 2, nsp--;
    }
    return 0;
}