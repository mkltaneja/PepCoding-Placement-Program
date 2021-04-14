#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int span(int n, vector<int> &arr, int d)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == d)
            return i;
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
    cout << span(n, arr, d);
}