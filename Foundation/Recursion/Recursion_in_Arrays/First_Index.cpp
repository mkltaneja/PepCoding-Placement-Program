#include <iostream>
#include <vector>
using namespace std;

int first_index(int i, int n, int x, vector<int> &arr)
{
    if (i == n)
        return -1;
    if (arr[i] == x)
        return i;
    return first_index(i + 1, n, x, arr);
}

int main()
{
    int n, x;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    cout << first_index(0, n, x, arr);
}