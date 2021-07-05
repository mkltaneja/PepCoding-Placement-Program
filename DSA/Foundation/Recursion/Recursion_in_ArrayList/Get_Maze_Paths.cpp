#include <iostream>
#include <vector>
using namespace std;

vector<string> get_maze_paths(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
        return {""};

    vector<string> ans;
    if (sc + 1 <= ec)
    {
        vector<string> arr = get_maze_paths(sr, sc + 1, er, ec);
        for (string s : arr)
            ans.push_back("h" + s);
    }
    if (sr + 1 <= er)
    {
        vector<string> arr = get_maze_paths(sr + 1, sc, er, ec);
        for (string s : arr)
            ans.push_back("v" + s);
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