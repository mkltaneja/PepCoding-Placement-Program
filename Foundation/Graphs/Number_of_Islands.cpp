#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, int j, int n, int m, vector<vector<int>> &gp)
{
    if (i < 0 || j < 0 || i >= n || j >= m || gp[i][j] == 1)
        return;
    gp[i][j] = 1;
    dfs(i + 1, j, n, m, gp);
    dfs(i, j + 1, n, m, gp);
    dfs(i - 1, j, n, m, gp);
    dfs(i, j - 1, n, m, gp);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gp(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> gp[i][j];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (gp[i][j] == 0)
            {
                dfs(i, j, n, m, gp);
                count++;
            }
        }
    }
    cout << count << endl;
}
