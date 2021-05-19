#include <iostream>
#include <vector>
using namespace std;

void combination2D(int r, int c, int placed, int n, vector<vector<int>> &box)
{
    if (placed == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!box[i][j])
                    cout << "-\t";
                else
                    cout << "q"
                         << "\t";
            }
            cout << "\n";
        }
        cout << endl;
        return;
    }
    for (int j = c; j < n; j++)
    {
        box[r][j] = 1;
        combination2D(r, j + 1, placed + 1, n, box);
        box[r][j] = 0;
    }
    for (int i = r + 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            box[i][j] = 1;
            combination2D(i, j + 1, placed + 1, n, box);
            box[i][j] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> box(n, vector<int>(n, 0));
    combination2D(0, 0, 0, n, box);
}