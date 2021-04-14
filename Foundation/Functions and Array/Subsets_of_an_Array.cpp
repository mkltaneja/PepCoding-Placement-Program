// METHOD 1 (By considering the sequence as binary sequence)
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void subsets(int i, int n, vector<int> &arr, string s)
{
    int count = pow(2, n);

    for (int i = 0; i < count; i++)
    {
        int x = i;
        string s = "";
        for (int j = n - 1; j >= 0; j--)
        {
            int rem = x % 2;
            x /= 2;

            if (rem == 0)
                s = "-\t" + s;
            else
                s = to_string(arr[j]) + "\t" + s;
        }
        cout << s << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    subsets(0, n, arr, "");
}

// METHOD 2 (Subsequence)

#include <iostream>
#include <vector>
using namespace std;

void subsets(int i, int n, vector<int> &arr, string s)
{
    if (i == n)
    {
        cout << s << endl;
        return;
    }
    subsets(i + 1, n, arr, s + "-\t");
    subsets(i + 1, n, arr, s + to_string(arr[i]) + "\t");
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    subsets(0, n, arr, "");
}