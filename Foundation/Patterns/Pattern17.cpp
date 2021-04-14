#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int nsp = n / 2, nst = 1;
    for (int i = 0; i < n; i++)
    {
        if (i == n / 2)
            for (int cst = 1; cst <= nsp; cst++)
                cout << "*\t";
        else
            for (int csp = 1; csp <= nsp; csp++)
                cout << "\t";
        for (int cst = 1; cst <= nst; cst++)
            cout << "*\t";

        cout << endl;

        if (i < n / 2)
            nst++;
        else
            nst--;
    }
    return 0;
}