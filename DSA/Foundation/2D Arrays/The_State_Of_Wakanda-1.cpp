#include <iostream>
#include <vector>
using namespace std;

void vakanda(int n, int m, vector<vector<int>> &arr)
{
    for (int j = 0; j < m; j++)
    {
        if (j % 2 == 0)
            for (int i = 0; i < n; i++)
                cout << arr[i][j] << endl;
        else
            for (int i = n - 1; i >= 0; i--)
                cout << arr[i][j] << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    vakanda(n, m, arr);
}