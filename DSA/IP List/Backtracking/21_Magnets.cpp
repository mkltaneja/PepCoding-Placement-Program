#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &cp, vector<int> &cm, vector<int> &rp, vector<int> &rm)
{
    for (int x : cp)
        if (x > 0)
            return false;
    for (int x : cm)
        if (x > 0)
            return false;
    for (int x : rp)
        if (x > 0)
            return false;
    for (int x : rm)
        if (x > 0)
            return false;
    return true;
}

bool isSafe(char c, int i, int j, vector<vector<char>> &ans, vector<int> &col, vector<int> &row)
{
    if (i && ans[i - 1][j] == c)
        return false;
    if (j && ans[i][j - 1] == c)
        return false;
    if (i != ans.size() - 1 && ans[i + 1][j] == c)
        return false;
    if (j != ans[0].size() - 1 && ans[i][j + 1] == c)
        return false;
    if (row[i] == 0)
        return false;
    if (col[j] == 0)
        return false;
    return true;
}

bool magnets(int idx, int n, int m, vector<vector<char>> &ans, vector<vector<char>> &board, vector<int> &cp, vector<int> &cm, vector<int> &rp, vector<int> &rm)
{
    if (idx == n * m)
    {
        if (isValid(cp, cm, rp, rm))
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    cout << ans[i][j] << " ";
                cout << endl;
            }
            return true;
        }
        return false;
    }
    int i = idx / m, j = idx % m;
    if (board[i][j] == 'B' || board[i][j] == 'R')
    {
        if (magnets(idx + 1, n, m, ans, board, cp, cm, rp, rm))
            return true;
    }
    else if (board[i][j] == 'L')
    {
        if (isSafe('+', i, j, ans, cp, rp) && isSafe('-', i, j + 1, ans, cm, rm))
        {
            ans[i][j] = '+';
            ans[i][j + 1] = '-';
            cp[j]--;
            cm[j + 1]--;
            rp[i]--;
            rm[i]--;
            if (magnets(idx + 2, n, m, ans, board, cp, cm, rp, rm))
                return true;
            ans[i][j] = 'X';
            ans[i][j + 1] = 'X';
            cp[j]++;
            cm[j + 1]++;
            rp[i]++;
            rm[i]++;
        }
        else if (isSafe('-', i, j, ans, cm, rm) && isSafe('+', i, j + 1, ans, cp, rp))
        {
            cm[j]--;
            cp[j + 1]--;
            rp[i]--;
            rm[i]--;
            ans[i][j] = '-';
            ans[i][j + 1] = '+';
            if (magnets(idx + 2, n, m, ans, board, cp, cm, rp, rm))
                return true;
            ans[i][j] = 'X';
            ans[i][j + 1] = 'X';
            cm[j]++;
            cp[j + 1]++;
            rp[i]++;
            rm[i]++;
        }
    }
    else if (board[i][j] == 'T')
    {
        if (isSafe('+', i, j, ans, cp, rp) && isSafe('-', i + 1, j, ans, cm, rm))
        {
            rp[i]--;
            rm[i + 1]--;
            cp[j]--;
            cm[j]--;
            ans[i][j] = '+';
            ans[i + 1][j] = '-';
            if (magnets(idx + 1, n, m, ans, board, cp, cm, rp, rm))
                return true;
            ans[i][j] = 'X';
            ans[i + 1][j] = 'X';
            rp[i]++;
            rm[i + 1]++;
            cp[j]++;
            cm[j]++;
        }
        else if (isSafe('-', i, j, ans, cm, rm) && isSafe('+', i + 1, j, ans, cp, rp))
        {
            rm[i]--;
            rp[i + 1]--;
            cp[j]--;
            cm[j]--;
            ans[i][j] = '-';
            ans[i + 1][j] = '+';
            if (magnets(idx + 1, n, m, ans, board, cp, cm, rp, rm))
                return true;
            ans[i][j] = 'X';
            ans[i + 1][j] = 'X';
            rm[i]++;
            rp[i + 1]++;
            cp[j]++;
            cm[j]++;
        }
    }
    if (magnets(idx + 1, n, m, ans, board, cp, cm, rp, rm))
        return true;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    vector<int> cp(m), rp(n), rm(n), cm(m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    for (int i = 0; i < m; i++)
        cin >> cp[i];
    for (int i = 0; i < n; i++)
        cin >> rp[i];
    for (int i = 0; i < n; i++)
        cin >> rm[i];
    for (int i = 0; i < m; i++)
        cin >> cm[i];

    vector<vector<char>> ans(n, vector<char>(m, 'X'));
    bool res = magnets(0, n, m, ans, board, cp, cm, rp, rm);
    if (!res)
        cout << "No Solution\n";
}