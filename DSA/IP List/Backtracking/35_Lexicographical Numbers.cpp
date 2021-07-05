#include <iostream>
#include <vector>
using namespace std;

void lexicographical(int x, int n)
{
    if (x > n)
        return;
    cout << x << endl;
    for (int i = 0; i <= 9; i++)
        lexicographical(x * 10 + i, n);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 9; i++)
        lexicographical(i, n);
}