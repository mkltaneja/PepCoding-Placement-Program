#include <iostream>
#include <vector>
using namespace std;

vector<string> get_stair_paths(int n)
{
    if (n == 0)
        return {""};

    vector<string> ans;
    for (int i = 1; i <= 3; i++)
    {
        if (n - i >= 0)
        {
            vector<string> arr = get_stair_paths(n - i);
            for (string s : arr)
                ans.push_back(to_string(i) + s);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> ans = get_stair_paths(n);
    cout << "[";
    for (int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << ", ";
    cout << ans[ans.size() - 1] << "]";
}