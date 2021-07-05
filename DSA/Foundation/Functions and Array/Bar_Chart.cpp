#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void bar_chart(int n, vector<int> &arr)
{
    int maxi = INT_MIN;
    for (int x : arr)
        maxi = max(maxi, x);

    for (int i = maxi; i > 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] >= i)
                cout << "*\t";
            else
                cout << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    bar_chart(n, arr);
}