#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int first_idx(int n, vector<int> &arr, int d)
{
    int st = 0, end = n - 1, ans = -1;

    while (st <= end)
    {
        int mid = (st + end) >> 1;
        if (arr[mid] == d)
        {
            end = mid - 1;
            ans = mid;
        }
        else if (arr[mid] < d)
            st = mid + 1;
        else if (arr[mid] > d)
            end = mid - 1;
    }
    return ans;
}
int last_idx(int n, vector<int> &arr, int d)
{
    int st = 0, end = n - 1, ans = -1;

    while (st <= end)
    {
        int mid = (st + end) >> 1;
        if (arr[mid] == d)
        {
            st = mid + 1;
            ans = mid;
        }
        else if (arr[mid] < d)
            st = mid + 1;
        else if (arr[mid] > d)
            end = mid - 1;
    }
    return ans;
}

int main()
{
    int n, d;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> d;

    int first = first_idx(n, arr, d);
    int last = last_idx(n, arr, d);
    if (first > last)
        first = -1, last = -1;
    cout << first << endl
         << last;
}