#include <iostream>
using namespace std;

void print_reverse_digits(int n)
{
    while (n)
    {
        cout << n % 10 << endl;
        n /= 10;
    }
}

int main()
{
    int n;
    cin >> n;

    print_reverse_digits(n);
}