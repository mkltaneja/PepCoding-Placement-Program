#include<iostream>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int ans = 0;
    while(n)
    {
        n -= (n & -n);
        ans++;
    }
    cout<<ans<<endl;
}