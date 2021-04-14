#include <iostream>
#include <vector>
using namespace std;

void subarrays(int n, vector<int> &arr)
{
    for (int i = 0; i < n; i++)
    {
        string s = to_string(arr[i]) + "\t";
        cout << s << endl;
        for (int j = i + 1; j < n; j++)
        {
            s += to_string(arr[j]) + "\t";
            cout << s << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    subarrays(n, arr);
}