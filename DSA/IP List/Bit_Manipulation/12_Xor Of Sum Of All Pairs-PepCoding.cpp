#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int xord = 0;
    for (int i : arr)
        xord ^= 2 * i;
    cout << xord;

    return 0;
}