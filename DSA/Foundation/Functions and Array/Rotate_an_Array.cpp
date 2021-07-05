#include <iostream>
#include <vector>
using namespace std;

void rotate_array(int n, int k, vector<int> &arr)
{
    vector<int> a(arr.begin(), arr.begin() + (n - k));
    vector<int> b(arr.begin() + (n - k), arr.end());
    arr.erase(arr.begin(), arr.begin() + (n - k));
    arr.insert(arr.end(), a.begin(), a.end());
}

void display(int n, vector<int> &arr)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;

    k = k % n;
    if (k < 0)
        k += n;
    // cout<<k;

    rotate_array(n, k, arr);
    display(n, arr);
}