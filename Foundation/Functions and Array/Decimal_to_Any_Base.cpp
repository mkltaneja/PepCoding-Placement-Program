#include <iostream>
#include <algorithm>
using namespace std;

string dectobase(int n, int b)
{
    string s = "";
    while (n)
    {
        s += to_string(n % b);
        n /= b;
    }
    reverse(s.begin(), s.end());

    return s;
}

int main()
{
    int n, b;
    cin >> n >> b;

    cout << dectobase(n, b);
}

// APPROACH 2 (Without String)
#include <iostream>
#include <algorithm>
using namespace std;

int dectobase(int n, int b)
{
    int ans = 0, p = 1;
    while (n)
    {
        ans += (n % b) * p;
        p *= 10;
        n /= b;
    }

    return ans;
}

int main()
{
    int n, b;
    cin >> n >> b;

    cout << dectobase(n, b);
}