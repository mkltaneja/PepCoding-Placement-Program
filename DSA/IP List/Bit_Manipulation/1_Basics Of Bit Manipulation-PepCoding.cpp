#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i, j, k, m;
    cin>>i>>j>>k>>m;
    
    cout<<(n | (1 << i))<<endl;
    cout<<(n & ~(1 << j))<<endl;
    cout<<(n ^ (1 << k))<<endl;
    cout<<((n & (1 << m))? "true" : "false")<<endl;
}