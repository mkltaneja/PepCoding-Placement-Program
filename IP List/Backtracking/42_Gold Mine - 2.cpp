#include <iostream>
#include <vector>
using namespace std;

int dfs(int i, int j, int n, int m, vector<vector<int>> &mine)
{
    if (i == -1 || j == -1 || i == n || j == m || mine[i][j] == 0)
        return 0;

    int gold = mine[i][j];
    mine[i][j] = 0;

    gold += dfs(i + 1, j, n, m, mine);
    gold += dfs(i, j + 1, n, m, mine);
    gold += dfs(i - 1, j, n, m, mine);
    gold += dfs(i, j - 1, n, m, mine);

    return gold;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mine(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mine[i][j];
    int maxgold = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mine[i][j])
                maxgold = max(maxgold, dfs(i, j, n, m, mine));
    cout << maxgold << endl;
}