#include <iostream>
#include <vector>
using namespace std;

vector<string> get_maze_paths(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
        return {""};

    vector<string> ans;
    for (int jump = 1; sc + jump <= ec; jump++)
    {
        vector<string> arr = get_maze_paths(sr, sc + jump, er, ec);
        for (string s : arr)
            ans.push_back("h" + to_string(jump) + s);
    }
    for (int jump = 1; sr + jump <= er; jump++)
    {
        vector<string> arr = get_maze_paths(sr + jump, sc, er, ec);
        for (string s : arr)
            ans.push_back("v" + to_string(jump) + s);
    }
    for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++)
    {
        vector<string> arr = get_maze_paths(sr + jump, sc + jump, er, ec);
        for (string s : arr)
            ans.push_back("d" + to_string(jump) + s);
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    if (n == 0 || m == 0)
    {
        cout << "[]" << endl;
        return 0;
    }
    vector<string> ans = get_maze_paths(0, 0, n - 1, m - 1);
    cout << "[";
    for (int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << ", ";
    cout << ans[ans.size() - 1] << "]";
}