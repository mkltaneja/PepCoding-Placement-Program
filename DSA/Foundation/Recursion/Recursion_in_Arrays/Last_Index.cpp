#include <iostream>
#include <vector>
using namespace std;

int last_index(int i, int n, int x, vector<int> &arr)
{
    if (i == -1)
        return -1;
    if (arr[i] == x)
        return i;
    return last_index(i - 1, n, x, arr);
}

int main()
{
    int n, x;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    cout << last_index(n - 1, n, x, arr);
}

// OR
// If we want to start the recursion from the begining
#include <iostream>
#include <vector>
using namespace std;

int last_index(int i, int n, int x, vector<int> &arr)
{
    if (i == n)
        return -1;
    int ans = last_index(i + 1, n, x, arr);
    if (ans == -1 && arr[i] == x)
        return ans = i;
    return ans;
}

int main()
{
    int n, x;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    cout << last_index(0, n, x, arr);
}