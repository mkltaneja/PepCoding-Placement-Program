#include <iostream>
#include <vector>
using namespace std;

void array_inverse(int n, vector<int> &arr)
{
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
        temp[arr[i]] = i;
    arr = temp;
}

void display(int n, vector<int> &arr)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    array_inverse(n, arr);
    display(n, arr);
}