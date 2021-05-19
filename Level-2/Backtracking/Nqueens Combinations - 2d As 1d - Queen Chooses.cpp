#include <iostream>
#include <vector>
using namespace std;

void nQueen(int idx, int placed, int n, vector<vector<int>> &box, int row, int col, int ldiag, int rdiag)
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
    for (int i = idx; i < n * n; i++)
    {
        int r = i / n, c = i % n;
        if (!(row & (1 << r)) && !(col & (1 << c)) && !(ldiag & (1 << (r + c))) &&
            !(rdiag & (1 << ((r - c) + n))))
        {
            box[r][c] = 1;
            row ^= (1 << r);
            col ^= (1 << c);
            ldiag ^= (1 << (r + c));
            rdiag ^= (1 << ((r - c) + n));
            nQueen(i + 1, placed + 1, n, box, row, col, ldiag, rdiag);
            box[r][c] = 0;
            row ^= (1 << r);
            col ^= (1 << c);
            ldiag ^= (1 << (r + c));
            rdiag ^= (1 << ((r - c) + n));
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> box(n, vector<int>(n, 0));
    int row = 0, col = 0, ldiag = 0, rdiag = 0;
    nQueen(0, 0, n, box, row, col, ldiag, rdiag);
}