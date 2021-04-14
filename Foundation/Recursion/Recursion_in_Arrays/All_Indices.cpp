#include <iostream>
#include <vector>
using namespace std;

vector<int> all_indices(int i, int size, int n, int x, vector<int> &arr)
{
    if (i == n)
        return vector<int>(size);

    vector<int> ans;
    if (arr[i] == x)
    {
        ans = all_indices(i + 1, size + 1, n, x, arr);
        ans[size] = i;
    }
    else
        ans = all_indices(i + 1, size, n, x, arr);
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
    vector<int> ans = all_indices(0, 0, n, x, arr);
    if (ans.size() == 0)
        cout << endl;
    else
        for (int x : ans)
            cout << x << endl;
}