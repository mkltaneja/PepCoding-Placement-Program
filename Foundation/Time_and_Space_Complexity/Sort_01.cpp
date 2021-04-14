#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sort01(int n, vector<int> &arr)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            cout << "Swapping index " << i << " and index " << j << endl;
            swap(arr[i], arr[j++]);
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
    sort01(n, arr);
    for (int x : arr)
        cout << x << endl;
}