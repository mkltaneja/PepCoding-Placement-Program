#include <iostream>
#include <vector>
using namespace std;

void permutation2D(int x, int n, vector<vector<int>> box)
{
    if (x == n + 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!box[i][j])
                    cout << "-\t";
                else
                    cout << "q" << box[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (box[i][j] == 0)
            {
                box[i][j] = x;
                permutation2D(x + 1, n, box);
                box[i][j] = 0;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> box(n, vector<int>(n, 0));
    permutation2D(1, n, box);
}