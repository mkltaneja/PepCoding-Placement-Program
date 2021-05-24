#include <iostream>
#include <vector>
using namespace std;

void solve_Sudoku(int idx, vector<int> &row, vector<int> &col, vector<vector<int>> &mat, vector<vector<int>> &board)
{
    if (idx == 81)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        return;
    }
    int i = idx / 9, j = idx % 9;
    int r = i / 3, c = j / 3;

    if (board[i][j] != 0)
        solve_Sudoku(idx + 1, row, col, mat, board);
    else
    {
        for (int x = 1; x <= 9; x++)
        {
            int mask = (1 << x);
            if (!(row[i] & mask) && !(col[j] & mask) && !(mat[r][c] & mask))
            {
                board[i][j] = x;
                row[i] ^= mask;
                col[j] ^= mask;
                mat[r][c] ^= mask;
                solve_Sudoku(idx + 1, row, col, mat, board);
                board[i][j] = 0;
                row[i] ^= mask;
                col[j] ^= mask;
                mat[r][c] ^= mask;
            }
        }
    }
}

int main()
{
    vector<vector<int>> board(90, vector<int>(90));
    vector<int> row(9, 0), col(9, 0);
    vector<vector<int>> mat(30, vector<int>(30, 0));

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
                continue;
            int mask = (1 << board[i][j]);
            row[i] ^= mask;
            col[j] ^= mask;
            mat[i / 3][j / 3] ^= mask;
        }
    }
    solve_Sudoku(0, row, col, mat, board);
}