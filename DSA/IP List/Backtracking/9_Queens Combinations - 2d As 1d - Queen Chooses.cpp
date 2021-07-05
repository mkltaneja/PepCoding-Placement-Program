#include <iostream>
#include <vector>
using namespace std;

void combination2D(int idx, int placed, int n, vector<vector<int>> &box)
{
    if (placed == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!box[i][j])
                    cout << "-	";
                else
                    cout << "q"
                         << "	";
            }
            cout << "
                    ";
        }
        cout << endl;
        return;
    }
    for (int i = idx; i < n * n; i++)
    {
        int r = i / n, c = i % n;
        box[r][c] = 1;
        combination2D(i + 1, placed + 1, n, box);
        box[r][c] = 0;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> box(n, vector<int>(n, 0));
    combination2D(0, 0, n, box);
}