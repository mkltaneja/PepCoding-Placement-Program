#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selection_sort(int n, vector<int> &arr)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mini = arr[i], idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < mini)
            {
                mini = arr[j];
                idx = j;
            }
        }
        swap(arr[idx], arr[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    selection_sort(n, arr);
    for (int x : arr)
        cout << x << " ";
}