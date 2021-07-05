#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    for (int i = n; i > 0; i--)
    {
        if (i == 1 || i == 5)
        {
            for (int j = 0; j < n; j++)
                cout << "*";
        }
        else
        {
            for (int j = i - 2; j >= 0; j--)
                cout << " ";
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}