#include <iostream>
#include <vector>
using namespace std;

void get_stair_paths(string ans, int n)
{
    if (n == 0)
    {
        cout << ans << endl;
        return;
    }

    for (int i = 1; i <= 3; i++)
        if (n - i >= 0)
            get_stair_paths(ans + to_string(i), n - i);
}

int main()
{
    int n;
    cin >> n;
    get_stair_paths("", n);
}