#include <iostream>
#include <vector>
using namespace std;

void display(int n, int m, vector<vector<int>> &arr)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    display(n, m, arr);
}

// SEGMENT TREE QUESTION=============================================================================================

// #include<bits/stdc++.h>
// #define vi vector<int>
// #define pii pair<int,int>
// #define vpii vector<pii>
// #define s second
// #define f first
// using namespace std;

// void buildmin(vi &a, vpii &seg, int i, int low, int high)
// {
//     if(low == high)
//     {
//         seg[i] = {a[low],low};
//         // cout<<i<<", "<<low<<", "<<high<<" -> "<<seg[i].f<<" "<<seg[i].s<<endl;
//         return;
//     }
//     int mid = (low+high)>>1;
//     buildmin(a, seg, 2*i+1, low, mid);
//     buildmin(a, seg, 2*i+2, mid+1, high);
//     // seg[i] = (seg[2*i+1].f < seg[2*i+2].f)? ({seg[2*i+1].f, seg[2*i+1].s}) : ({seg[2*i+2].f, seg[2*i+2].s});
//     if(seg[2*i+1].f < seg[2*i+2].f)
//         seg[i] = {seg[2*i+1].f, seg[2*i+1].s};
//     else 
//         seg[i] = {seg[2*i+2].f, seg[2*i+2].s};
//     // cout<<i<<", "<<low<<", "<<high<<" -> "<<seg[i].f<<" "<<seg[i].s<<endl;
// }

// void buildmax(vi &a, vpii &seg, int i, int low, int high)
// {
//     if(low == high)
//     {
//         seg[i] = {a[low],low};
//         return;
//     }
//     int mid = (low+high)>>1;
//     buildmax(a, seg, 2*i+1, low, mid);
//     buildmax(a, seg, 2*i+2, mid+1, high);
//     // seg[i] = (seg[2*i+1].f < seg[2*i+2].f)? ({seg[2*i+1].f, seg[2*i+1].s}) : ({seg[2*i+2].f, seg[2*i+2].s});
//     if(seg[2*i+1].f > seg[2*i+2].f)
//         seg[i] = {seg[2*i+1].f, seg[2*i+1].s};
//     else 
//         seg[i] = {seg[2*i+2].f, seg[2*i+2].s};
// }


// void querymin(vi &a, vpii &seg, int l, int r, int x, int i, int low, int high)
// {
//     if(low >= l && high <= r)
//     {
//         seg[i] = {x,l};
//         return;
//     }
//     if(low > r || high < l) return;

//     if(seg[i].f > x) seg[i] = {x,l};

//     int mid = (low+high)>>1;
//     querymin(a, seg, l, r, x, 2*i+1, low, mid);
//     querymin(a, seg, l, r, x, 2*i+1, mid+1, high);
// }

// void querymax(vi &a, vpii &seg, int l, int r, int x, int i, int low, int high)
// {
//     if(low >= l && high <= r)
//     {
//         seg[i] = {x,l};
//         return;
//     }
//     if(low > r || high < l) return;

//     if(seg[i].f < x) seg[i] = {x,l};

//     int mid = (low+high)>>1;
//     querymin(a, seg, l, r, x, 2*i+1, low, mid);
//     querymin(a, seg, l, r, x, 2*i+1, mid+1, high);
// }


// int main()
// {
//     int n, q;
//     cin>>n>>q;
//     vpii sa1(4*n), sa2(4*n), sb1(4*n), sb2(4*n);
//     vi a(n), b(n);
//     for(int i = 0; i < n; i++)
//         cin>>a[i];
//     for(int i = 0; i < n; i++)
//         cin>>b[i];

//     // cout<<"a: \n";
//     buildmin(a, sa1, 0, 0, n-1);
//     buildmax(a, sa2, 0, 0, n-1);
//     // cout<<"b: \n";
//     buildmin(b, sb1, 0, 0, n-1);
//     buildmax(b, sb2, 0, 0, n-1);


    
//     for(int i = 0; i < q; i++)
//     {
//         char c;
//         cin>>c;
//         cout<<c<<endl;
//         if(c == '?')
//         {
//             int A = (sa2[0].f - sa1[0].f) + (b[sa2[0].s] - b[sa1[0].s]);
//             int B = (sb2[0].f - sb1[0].f) + (a[sb2[0].s] - a[sb1[0].s]);
//             cout<<sa1[0].f<<" "<<sa2[0].f<<endl;
//             cout<<b[sa1[0].s]<<" "<<b[sa2[0].s]<<endl;
//             cout<<sb1[0].f<<" "<<sb2[0].f<<endl;
//             cout<<a[sb1[0].s]<<" "<<a[sb2[0].s]<<endl;
//             // cout<<A<<" "<<B<<endl;
//             if(A > B)
//                 cout<<A<<"\n";
//             else
//                 cout<<B<<"\n";
//         }
//         else if(c == 'a')
//         {
//             int x, y;
//             cin>>x>>y;
//             a[x-1] = y;
//             querymin(a, sa1, x-1, x-1, y, 0, 0, n-1);
//             querymax(a, sa2, x-1, x-1, y, 0, 0, n-1);
//         }
//         else
//         {
//             int x, y;
//             cin>>x>>y;
//             b[x-1] = y;
//             querymin(b, sb1, x-1, x-1, y, 0, 0, n-1);
//             querymax(b, sb2, x-1, x-1, y, 0, 0, n-1);
//         }
//     }
//     return 0;
// }



// #include<bits/stdc++.h>
// #define ull unsigned long long
// #define vull vector<ull>
// #define pull pair<ull,ull>
// #define vpull vector<pull>
// #define s second
// #define f first
// using namespace std;

// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         ull n, k;
//         cin>>n;
//         vull a(n), b(n), p(n);
//         for(int i = 0; i < n; i++)
//             cin>>a[i];
//         for(int i = 0; i < n; i++)
//             cin>>b[i];
//         cin>>k;
//         priority_queue<pull> pq1, pq2;
//         ull tot = 0;
//         for(int i = 0; i < n; i++)
//         {
//             pq1.push({(a[i]*b[i])-((a[i]/2)*b[i]), i});
//             pq2.push({(b[i]*a[i])-((b[i]/2)*a[i]), i});
//             tot += a[i]*b[i];
//             cout<<(b[i]*a[i])-((a[i]/2)*b[i])<<endl;
//             cout<<(b[i]*a[i])-((b[i]/2)*a[i])<<endl<<endl;
//         }
//         // cout<<tot<<endl;
//         ull x=0, y=0, t1=tot, t2=tot;
//         while(t1 > k)
//         {
//             pull tp = pq1.top();
//             pq1.pop();
//             t1 -= tp.f;
//             a[tp.s] /= 2;
//             pq2.push({(a[tp.s]*b[tp.s])-((a[tp.s]/2)*b[tp.s]), tp.s});
//             x++;
//         }
//         while(t2 > k)
//         {
//             pull tp = pq2.top();
//             pq2.pop();
//             t2 -= tp.f;
//             b[tp.s] /= 2;
//             pq2.push({(b[tp.s]*a[tp.s])-((b[tp.s]/2)*a[tp.s]), tp.s});
//             y++;
//         }
//         // cout<<x<<" "<<y<<endl;
//         if(x < y) cout<<"Alice\n";
//         else if(y < x) cout<<"Bob\n";
//         else cout<<"Tie\n";
//     }
//     return 0;
// }











