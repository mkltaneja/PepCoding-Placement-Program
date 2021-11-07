#include<bits/stdc++.h>
using namespace std;

int fh = 0, flw = 0, frw = 0;

int fib(int n, int h, int lw, int rw)
{
    if(n == 1 || n == 0)
    {
        fh = max(fh, h);
        flw = min(flw, lw);
        frw = max(frw, rw);
        return n;
    }
    return fib(n-1, h+1, lw-1, rw+1) + fib(n-2, h+1, lw-1, rw+1);
}

void display()
{
    vector<vector<int>> tree(fh, vector<int> (frw-flw+1));
    for(int i = 0; i < tree.size(); i++)
    {
        for(int j = 0; j < tree[0].size(); j++)
        {
            if(tree[i][j])
        }
    }
}

int main()
{
    int n;
    cin>>n;
    fib(n, 1, 0, 1);
    display();
}