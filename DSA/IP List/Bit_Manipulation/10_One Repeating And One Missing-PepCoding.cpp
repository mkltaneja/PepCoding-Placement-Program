#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr.push_back(i + 1);
    }

    int combx = 0;
    for (int i = 0; i < 2 * n; i++)
        combx ^= arr[i];

    int rmsb = (combx & -combx);
    int a = 0, b = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (arr[i] & rmsb)
            a ^= arr[i];
        else
            b ^= arr[i];
    }
    for (int i = 0; i < 2 * n; i++)
    {
        if (arr[i] == a)
        {
            cout << "Missing Number -> " << b << endl;
            cout << "Repeating Number -> " << a << endl;
            break;
        }
        else if (arr[i] == b)
        {
            cout << "Missing Number -> " << a << endl;
            cout << "Repeating Number -> " << b << endl;
            break;
        }
    }
}