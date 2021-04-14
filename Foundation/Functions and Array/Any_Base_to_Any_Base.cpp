#include <iostream>
#include <algorithm>
using namespace std;

unsigned long int basetodec(string &n, int b)
{
    unsigned long int ans = 0, p = 1, i = -1;
    cout<<i<<endl;
    while (i >= 0)
    {
        ans += (n[i]-'0') * p;
        // cout<<n[i--]-'0'<<" ";
        if(i == -1)
            break;
        p *= b;
        // n /= 10;
    }

    return ans;
}
int dectobase(int n, int b)
{
    int ans = 0, p = 1;
    while (n)
    {
        ans += (n % b) * p;
        p *= 10;
        n /= b;
    }

    return ans;
}

int main()
{
    string n;
    int b1, b2;
    cin >> n >> b1 >> b2;

    unsigned long int dec = basetodec(n, b1);
    cout<<dec;
    // cout << dectobase(dec, b2);
}