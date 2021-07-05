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

void gcc(int i, vector<vector<Edge *>> &gp, vector<bool> &vis)
{
    vis[i] = true;
    for (Edge *e : gp[i])
        if (!vis[e->v])
            gcc(e->v, gp, vis);
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<Edge *>> gp(n);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w, gp);
    }

    vector<bool> vis(n, false);
    int comps = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            comps++;
            gcc(i, gp, vis);
        }
    }
    cout << (boolalpha) << (comps == 1) << endl;
    // write your code here
}
