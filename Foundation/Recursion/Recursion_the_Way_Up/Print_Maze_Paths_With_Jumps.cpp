#include <iostream>
#include <vector>
using namespace std;

void print_maze_paths(int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return;
    }
    for (int jump = 1; sc + jump <= ec; jump++)
        print_maze_paths(sr, sc + jump, er, ec, ans + "h" + to_string(jump));
    for (int jump = 1; sr + jump <= er; jump++)
        print_maze_paths(sr + jump, sc, er, ec, ans + "v" + to_string(jump));
    for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++)
        print_maze_paths(sr + jump, sc + jump, er, ec, ans + "d" + to_string(jump));
}

int main()
{
    int n, m;
    cin >> n >> m;
    print_maze_paths(0, 0, n - 1, m - 1, "");
}