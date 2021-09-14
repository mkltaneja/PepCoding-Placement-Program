#include <iostream>
#include <vector>
using namespace std;

int nonRepeating(int n, vector<int> &arr)
{
    int ans = 0;
    for(int x : arr) ans ^= x;
    
    return ans;
}

int main(int argc, char **argv)
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cout<<nonRepeating(n, arr)<<endl;
}