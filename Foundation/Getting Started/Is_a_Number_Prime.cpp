#include <iostream>
using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (isPrime(n))
            cout << "prime" << endl;
        else
            cout << "not prime" << endl;
    }

    return 0;
}