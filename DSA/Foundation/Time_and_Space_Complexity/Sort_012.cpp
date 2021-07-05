#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sort012(int n, vector<int> &arr)
{
    int j = 0, k = n - 1;
    for (int i = 0; i <= k; i++)
    {
        bool flag = false;
        if (arr[i] == 0)
        {
            if (arr[j] == 2)
                flag = true;
            cout << "Swapping index " << i << " and index " << j << endl;
            swap(arr[i], arr[j++]);
        }
        else if (arr[i] == 2)
        {
            if (arr[k] == 0 || arr[k] == 2)
                flag = true;
            cout << "Swapping index " << i << " and index " << k << endl;
            swap(arr[i], arr[k--]);
        }
        if (flag)
            i--;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int i = n-1;
    for(; -i; i--)
        cout<<arr[i]<<" ";
    cout<<endl<<i;
    // sort012(n, arr);
    // for (int x : arr)
    //     cout << x << endl;
}