#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nsp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int csp = 1; csp <= nsp; csp++)
            cout << "\t";
        cout << "*" << endl;
        nsp++;
    }
    return 0;
}