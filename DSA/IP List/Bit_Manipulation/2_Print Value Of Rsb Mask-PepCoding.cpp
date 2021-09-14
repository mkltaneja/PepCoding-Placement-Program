#include<iostream>
#include<algorithm>
using namespace std;

string tobin(int x)
{
    string ans = "";
    while(x)
    {
        ans += char((x % 2) + '0');
        x /= 2;
    }
    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int x = (n & (-n));
    cout<<tobin(x)<<endl;
}