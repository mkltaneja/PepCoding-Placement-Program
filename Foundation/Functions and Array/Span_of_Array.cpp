#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int span(int n, vector<int> &arr)
{
    int maxi = INT_MIN, mini = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
    }
    return (maxi - mini);
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cout<<span(n, arr);
}