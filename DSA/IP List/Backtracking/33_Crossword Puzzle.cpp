#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<vector<char>> &board)
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (board[i][j] == '-')
                return false;
    return true;
}

bool canPlaceHorizontal(int i, int j, vector<vector<char>> &board, string &word)
{
    int k = 0;
    while (j < 10 && (board[i][j] == '-' || board[i][j] == word[k]))
    {
        k++;
        j++;
    }
    return (k == word.size() && (j == 10 || board[i][j + 1] != '-'));
}

bool canPlaceVertical(int i, int j, vector<vector<char>> &board, string &word)
{
    int k = 0;
    while (i < 10 && (board[i][j] == '-' || board[i][j] == word[k]))
    {
        k++;
        i++;
    }
    return (k == word.size() && (i == 10 || board[i + 1][j] != '-'));
}

string placeHorizontal(int i, int j, vector<vector<char>> &board, string &word)
{
    string stored = "";
    for (int k = 0; k < word.size(); k++)
    {
        stored += board[i][j];
        board[i][j++] = word[k];
    }
    return stored;
}

string placeVertical(int i, int j, vector<vector<char>> &board, string &word)
{
    string stored = "";
    for (int k = 0; k < word.size(); k++)
    {
        stored += board[i][j];
        board[i++][j] = word[k];
    }
    return stored;
}

void unplaceHorizontal(int i, int j, vector<vector<char>> &board, string &stored)
{
    for (int k = 0; k < stored.size(); k++)
        board[i][j++] = stored[k];
}

void unplaceVertical(int i, int j, vector<vector<char>> &board, string &stored)
{
    for (int k = 0; k < stored.size(); k++)
        board[i++][j] = stored[k];
}

bool crossword(int idx, int n, vector<string> &words, vector<vector<char>> &board)
{
    cout<<idx<<endl;
    if (idx == n)
    {
        if (isValid(board))
        {
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                    cout << board[i][j];
                cout << endl;
            }
            return true;
        }
        return false;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (canPlaceHorizontal(i, j, board, words[idx]))
            {
                cout<<i<<", "<<j<<endl;
                string stored = placeHorizontal(i, j, board, words[idx]);
                cout<<"1 = "<<stored<<endl;
                if (crossword(idx + 1, n, words, board))
                    return true;
                unplaceHorizontal(i, j, board, stored);
            }
            if (canPlaceVertical(i, j, board, words[idx]))
            {
                cout<<i<<", "<<j<<endl;
                string stored = placeVertical(i, j, board, words[idx]);
                cout<<"2 = "<<stored<<endl;
                if (crossword(idx + 1, n, words, board))
                    return true;
                unplaceVertical(i, j, board, stored);
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board(10, vector<char>(10));
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> board[i][j];
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];
    bool ans = crossword(0, n, words, board);
    if (!ans)
        cout << "No Solution";
}