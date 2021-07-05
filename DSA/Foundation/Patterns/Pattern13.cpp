#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int n = 0; n < N; n++)
    {
        int nCr = 1;
        for (int r = 0; r <= n; r++)
        {
            cout << nCr << "\t";
            nCr = nCr * (n - r) / (r + 1);
        }
        cout << endl;
    }

    return 0;
}