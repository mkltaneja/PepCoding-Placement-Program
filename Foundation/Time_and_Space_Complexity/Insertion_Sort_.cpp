#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertion_sort(int n, vector<int> &arr)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            cout << "Comparing " << arr[j + 1] << " and " << arr[j] << endl;
            if (arr[j] > arr[j + 1])
            {
                cout << "Swapping " << arr[j] << " and " << arr[j + 1] << endl;
                swap(arr[j], arr[j + 1]);
            }
            else
                break;
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
    insertion_sort(n, arr);
    for (int x : arr)
        cout << x << endl;
}