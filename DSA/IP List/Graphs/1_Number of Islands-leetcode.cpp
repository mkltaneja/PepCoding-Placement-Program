
void dfs(int i, int j, int n, int m, vector<vector<char>> &grid)
{
    if (i == n || j == m || i == -1 || j == -1 || grid[i][j] == '0')
        return;

    grid[i][j] = '0';

    dfs(i + 1, j, n, m, grid);
    dfs(i, j + 1, n, m, grid);
    dfs(i - 1, j, n, m, grid);
    dfs(i, j - 1, n, m, grid);
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size(), m = grid[0].size();

    int islands = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                islands++;
                dfs(i, j, n, m, grid);
            }
        }
    }
    return islands;
}