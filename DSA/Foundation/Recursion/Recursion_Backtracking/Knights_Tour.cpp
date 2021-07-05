#include <iostream>
#include <vector>
using namespace std;

void knights_tour(int n, int i, int j, vector<vector<int>> &ans, int visited)
{
    if (i < 0 || j < 0 || i >= n || j >= n || ans[i][j] > 0)
        return;
    // cout<<visited<<endl;
    if (visited == n * n)
    {
        ans[i][j] = visited;

        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
                cout << ans[r][c] << " ";
            cout << endl;
        }
        cout << endl;

        ans[i][j] = 0;
        return;
    }
    // cout<<i<<", "<<j<<endl;
    ans[i][j] = visited;
    knights_tour(n, i - 2, j + 1, ans, visited + 1);
    knights_tour(n, i - 1, j + 2, ans, visited + 1);
    knights_tour(n, i + 1, j + 2, ans, visited + 1);
    knights_tour(n, i + 2, j + 1, ans, visited + 1);
    knights_tour(n, i + 2, j - 1, ans, visited + 1);
    knights_tour(n, i + 1, j - 2, ans, visited + 1);
    knights_tour(n, i - 1, j - 2, ans, visited + 1);
    knights_tour(n, i - 2, j - 1, ans, visited + 1);
    ans[i][j] = 0;
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    knights_tour(n, x, y, ans, 1);
}