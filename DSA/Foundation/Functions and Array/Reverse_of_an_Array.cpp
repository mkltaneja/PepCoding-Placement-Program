#include <iostream>
#include <vector>
using namespace std;

void reverse_array(int n, vector<int> &arr)
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

void display(int n, vector<int> &arr)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    reverse_array(n, arr);
    display(n, arr);
}