#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int nsp1 = n / 2 - 1, nsp2 = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0 || j == n - 1)
                cout << "*\t";
            else if (i >= n / 2 && (i == j || (i + j) == n - 1))
                cout << "*\t";
            else
                cout << "\t";
        }
        cout << endl;
    }
    return 0;
}