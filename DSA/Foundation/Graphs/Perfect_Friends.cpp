#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Edge
{
public:
    int v;
    int w;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

void addEdge(int u, int v, int w, vector<vector<Edge *>> &gp)
{
    gp[u].push_back(new Edge(v, w));
    gp[v].push_back(new Edge(u, w));
}

void gcc(int i, vector<vector<Edge *>> &gp, vector<bool> &vis, int &count)
{
    // cout<<i<<" - ";
    vis[i] = true;
    count++;
    for (Edge *e : gp[i])
        if (!vis[e->v])
            gcc(e->v, gp, vis, count);
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<Edge *>> gp(n);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v, 0, gp);
    }

    vector<bool> vis(n, false);
    vector<int> comps;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            int count = 0;
            gcc(i, gp, vis, count);
            // cout<<endl;
            comps.push_back(count);
            // cout<<i<<" - "<<count<<endl;
        }
    }
    int ans = 0;
    for (int x : comps)
        ans += x * (n - x);
    cout << ans / 2 << endl;
    // write your code here
}
