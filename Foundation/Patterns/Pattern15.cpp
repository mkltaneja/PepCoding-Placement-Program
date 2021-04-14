#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int nst = 1, nsp = n / 2, num;
    for (int i = 1; i <= n; i++)
    {
        if (i <= n / 2)
            num = i;
        else
            num = n - i + 1;
        for (int csp = 1; csp <= nsp; csp++)
            cout << "\t";
        for (int cst = 1; cst <= nst; cst++)
        {
            cout << num << "\t";
            if (cst <= nst / 2)
                num++;
            else
                num--;
        }
        cout << endl;
        if (i <= n / 2)
        {
            nsp--;
            nst += 2;
        }
        else
        {
            nsp++;
            nst -= 2;
        }
    }

    return 0;
}