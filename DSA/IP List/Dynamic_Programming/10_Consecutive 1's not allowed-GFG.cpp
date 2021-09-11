
// #define ll long long
ll countStrings(int n) 
{
    ll c0 = 1, c1 = 1;
    for(int i = 2; i <= n; i++)
    {
        ll tmp = c0;
        c0 = c0 + c1;
        c1 = tmp;
    }
    return c0 + c1;
}