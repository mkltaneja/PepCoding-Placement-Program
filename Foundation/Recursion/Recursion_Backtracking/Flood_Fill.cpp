#include <iostream>
#include <vector>
using namespace std;

void flood_fill(int i, int j, int n, int m, vector<vector<int>> &arr, string path, vector<vector<bool>> &vis)
{
    if (i < 0 || j < 0 || i == n || j == m || arr[i][j] == 1 || vis[i][j])
        return;
    if (i == n - 1 && j == m - 1)
    {
        cout << path << endl;
        return;
    }
    vis[i][j] = true;
    flood_fill(i - 1, j, n, m, arr, path + "t", vis);
    flood_fill(i + 1, j, n, m, arr, path + "d", vis);
    flood_fill(i, j + 1, n, m, arr, path + "r", vis);
    flood_fill(i, j - 1, n, m, arr, path + "l", vis);
    vis[i][j] = false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    flood_fill(0, 0, n, m, arr, "", vis);
}