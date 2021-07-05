#include <iostream>
#include <vector>
using namespace std;

void zigzag(int i, int n, vector<int> &arr)
{
    if (i == n)
        return;
    zigzag(i + 1, n, arr);
    cout << arr[i] << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    zigzag(0, n, arr);
}