#include <iostream>
#include <vector>
using namespace std;

void nQueen(int placed, int n, vector<vector<int>> &box, int row, int col, int ldiag, int rdiag)
{
    if (placed == n + 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!box[i][j])
                    cout << "-	";
                else
                    cout << "q" << box[i][j] << "	";
            }
            cout << "
                    ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n * n; i++)
    {
        int r = i / n, c = i % n;
        if (!(row & (1 << r)) && !(col & (1 << c)) && !(ldiag & (1 << (r + c))) &&
            !(rdiag & (1 << ((r - c) + n))))
        {
            box[r][c] = placed;
            row ^= (1 << r);
            col ^= (1 << c);
            ldiag ^= (1 << (r + c));
            rdiag ^= (1 << ((r - c) + n));
            nQueen(placed + 1, n, box, row, col, ldiag, rdiag);
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
    nQueen(1, n, box, row, col, ldiag, rdiag);
}