#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxi = INT_MIN;
int maxofArray(int i, int n, vector<int> &arr)
{
    if (i == n)
        return -1;

    maxi = maxofArray(i + 1, n, arr);
    return max(maxi, arr[i]);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxofArray(0, n, arr);
}