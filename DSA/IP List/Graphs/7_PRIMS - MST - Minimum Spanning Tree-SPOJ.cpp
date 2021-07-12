

// NOTE1:- MST is only defined for the undirected graphs
// NOTE2:- MST can also handle -ve weights
// NOTE3:- MST has time complexity -> O(ElogE/ElogV)
// NOTE4:- In MST, we minimize the overall graph





#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long int
#define ull unsigned long long int
#define pii pair<int, int>
#define pib pair<int, bool>
#define pbi pair<bool, int>
#define pbb pair<bool, bool>
#define pic pair<int, char>
#define pci pair<char, int>
#define pcc pair<char, char>
#define pis pair<int, string>
#define psi pair<string, int>
#define pss pair<string, string>
#define vi vector<int>
#define vvi vector<vi>
#define vd vector<double>
#define vvd vector<vd>
#define vll vector<ll>
#define vvll vector<vll>
#define vull vector<ull>
#define vvull vector<vull>
#define vb vector<bool>
#define vvb vector<vb>
#define vc vector<char>
#define vvc vector<vc>
#define vs vector<string>
#define vvs vector<vs>
#define vpii vector<pii>
#define vpbi vector<pbi>
#define vpib vector<pib>
#define vpbb vector<pbb>
#define vpci vector<pci>
#define vpic vector<pic>
#define vpcc vector<pcc>
#define vpsi vector<psi>
#define vpis vector<pis>
#define vpss vector<pss>
#define um unordered_map
#define umii unordered_map<int, int>
#define umci unordered_map<char, int>
#define umic unordered_map<int, char>
#define umsi unordered_map<string, int>
#define umis unordered_map<int, string>
#define omii map<int, int>
#define omci map<char, int>
#define omic map<int, char>
#define omsi map<string, int>
#define omis map<int, string>
#define p_q priority_queue<int>
#define p_ql priority_queue<l>
#define p_qll priority_queue<ll>
#define p_qull priority_queue<ull>
#define lp(i, a, b) for (int i = a; i < b; i++)
#define lpr(i, b, a) for (int i = b; i > a; i--)
#define lpl(i, a, b) for (ll i = a; i < b; i++)
#define lplr(i, b, a) for (ll i = b; i > a; i--)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define fastio(){ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);}
#define mod 1000000007

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
ll binpowmod(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

bool ispal(string &a)
{
    for (int i = 0; i < a.size() / 2; i++)
        if (a[i] != a[a.size() - i - 1])
            return false;
    return true;
}

void display(int n, vi &a)
{
    for(int x : a) cout<<x<<" ";
    cout<<"\n";
}
void display(int n, int m, vvi &a)
{
    lp(i, 0, n)
    {
        lp(j, 0, m)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

//////////////////////////////////////////////////////////////////MUKUL TANEJA///////////////////////////////////////////////////

struct comp
{
    bool operator()(pii const &a, pii const &b)
    {
        return a.s > b.s;
    }
};

void solve(int n, vector<vpii> &gp)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
    pq.push({1,0});

    vb vis(n+1, false);

    ull minw = 0;
    while(!pq.empty())
    {
        auto tp = pq.top();
        pq.pop();
        if(vis[tp.f]) continue;

        minw += tp.s;
        vis[tp.f] = true;

        for(auto v : gp[tp.f])
            if(!vis[v.f])
                pq.push({v.f, v.s});
    }
    cout<<minw<<"\n";
}

int main()
{
    fastio();

    int n, m;
    cin>>n>>m;
    vector<vpii> gp(n+1);
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        gp[u].push_back({v,w});
        gp[v].push_back({u,w});
    }

    solve(n, gp);

    return 0;
}
