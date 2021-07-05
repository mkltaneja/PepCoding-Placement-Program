#include <iostream>
using namespace std;

void decreasing(int a, int n)
{
    if (a == n + 1)
        return;

    decreasing(a + 1, n);
    cout << a << endl;
}

int main()
{
    int n;
    cin >> n;
    decreasing(1, n);
}