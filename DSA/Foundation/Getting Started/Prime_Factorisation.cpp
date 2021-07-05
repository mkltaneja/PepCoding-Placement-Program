#include <iostream>
using namespace std;

void prime_fatorisation(int n)
{
    for (int i = 2; n != 1; i++)
    {
        while (n % i == 0)
        {
            n /= i;
            cout << i << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;

    prime_fatorisation(n);

    return 0;
}