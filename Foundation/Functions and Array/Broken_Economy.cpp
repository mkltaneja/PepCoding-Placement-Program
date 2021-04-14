#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int Solution(int n, vector<int> &arr, int d)
{
    int greater = INT_MAX, smaller = INT_MIN;
    for (int x : arr)
    {
        if (x == d)
            return x;
        if (x < d && x > smaller)
            smaller = x;
        if (x > d && x < greater)
            greater = x;
    }
    cout << greater << endl
         << smaller;

    return -1;
}

int main()
{
    int n, d;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> d;

    int ans = Solution(n, arr, d);
    if (ans != -1)
        cout << ans;
}