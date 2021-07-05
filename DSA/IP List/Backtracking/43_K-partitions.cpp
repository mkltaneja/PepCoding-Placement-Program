#include <iostream>
#include <vector>
using namespace std;

int cnt = 1;
void display(int n, vector<vector<int>> &arr)
{
    cout << cnt++ << ". ";
    for (int i = 0; i < n; i++)
    {
        cout << "[";
        for (int j = 0; j < arr[i].size() - 1; j++)
            cout << arr[i][j] << ", ";
        cout << arr[i][arr[i].size() - 1] << "] ";
    }
    cout << "\n";
}

void kpartitions(int x, int n, int k, vector<vector<int>> &arr)
{
    if (x == n + 1)
    {
        if (k == 0)
            display(arr.size(), arr);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (!arr[i].empty())
        {
            arr[i].push_back(x);
            kpartitions(x + 1, n, k, arr);
            arr[i].pop_back();
        }
        else
        {
            arr[i].push_back(x);
            kpartitions(x + 1, n, k - 1, arr);
            arr[i].pop_back();
            break;
        }
    }
}

int main()
{
    int n, k;
    cout<<n<<", "<<k<<endl;
    cin >> n >> k;
    vector<vector<int>> arr(k, vector<int>());
    kpartitions(1, n, k, arr);
}