#include<iostream>
using namespace std;

int digits(int n)
{
    int count = 0;
    while(n)
    {
        count++;
        n /= 10;
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    
    cout<<digits(n)<<endl;
    
    return 0;
}