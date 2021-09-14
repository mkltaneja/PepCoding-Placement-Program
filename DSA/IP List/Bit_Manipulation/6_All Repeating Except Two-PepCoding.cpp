#include <iostream>
#include <vector>
using namespace std;

void nonRepeating(int n, vector<int> &arr)
{
    int comb = 0;
    for(int x : arr) comb ^= x;
    
    int ans0 = 0, ans1 = 0;
    int i = (comb & -comb);
    for(int x : arr)
    {
        if(x & i) ans1 ^= x;
        else ans0 ^= x;
    }
    cout<<min(ans0, ans1)<<endl<<max(ans0, ans1)<<endl;
}

int main(int argc, char **argv)
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    nonRepeating(n, arr);
}