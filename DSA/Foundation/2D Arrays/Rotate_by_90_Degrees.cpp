
// METHOD 1 (Using extra space) --> VALID FOR ANY n*m MATRIX
#include <iostream>
#include <vector>
using namespace std;

void rotate(int n, int m, vector<vector<int>> &arr)
{
    vector<vector<int>> ans(m, vector<int>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            ans[i][j] = arr[n - 1 - j][i];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    rotate(n, n, arr);
}

// METHOD 2 (Without extra space) --> VALID ONLY FOR n*n MATRIX
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(int n, vector<vector<int>> &arr)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            swap(arr[i][j], arr[j][i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n / 2; j++)
            swap(arr[i][j], arr[i][n - 1 - j]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    rotate(n, arr);
}