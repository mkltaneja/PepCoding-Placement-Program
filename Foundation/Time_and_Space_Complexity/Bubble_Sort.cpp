#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubble_sort(int n, vector<int> &arr)
{
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n - i; j++)
            if (arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    bubble_sort(n, arr);
    for (int x : arr)
        cout << x << " ";
}