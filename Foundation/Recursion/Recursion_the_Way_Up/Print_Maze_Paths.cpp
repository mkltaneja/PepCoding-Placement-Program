#include <iostream>
#include <vector>
using namespace std;

void get_maze_paths(int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return;
    }

    if (sc + 1 <= ec)
        get_maze_paths(sr, sc + 1, er, ec, ans + "h");
    if (sr + 1 <= er)
        get_maze_paths(sr + 1, sc, er, ec, ans + "v");
}

int main()
{
    int n, m;
    cin >> n >> m;
    get_maze_paths(0, 0, n - 1, m - 1, "");
}