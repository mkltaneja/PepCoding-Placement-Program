#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int i, int j, int n, vector<vector<bool>> &board)
{
    if (i - 2 >= 0 && j - 1 >= 0 && board[i - 2][j - 1])
        return false;
    if (i - 1 >= 0 && j - 2 >= 0 && board[i - 1][j - 2])
        return false;
    if (i - 2 >= 0 && j + 1 >= 0 && board[i - 2][j + 1])
        return false;
    if (i - 1 >= 0 && j + 2 >= 0 && board[i - 1][j + 2])
        return false;
    return true;
}

void nKnights(int idx, int placed, int n, vector<vector<bool>> &board)
{
    // cout<<idx<<endl;
    if (placed == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j])
                    cout << "k\t";
                else
                    cout << "-\t";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    for (int i = idx; i < n * n; i++)
    {
        int r = i / n, c = i % n;
        if (isSafe(r, c, n, board))
        {
            board[r][c] = true;
            nKnights(i + 1, placed + 1, n, board);
            board[r][c] = false;
        }
        // else cout<<"FALSE\n";
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<bool>> board(n, vector<bool>(n, false));
    nKnights(0, 0, n, board);
}