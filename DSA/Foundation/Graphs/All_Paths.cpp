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

void allPaths(int src, int dest, vector<bool> &vis, vector<vector<Edge *>> &gp, string path)
{
    if (src == dest)
    {
        cout << path << endl;
        return;
    }
    for (Edge *e : gp[src])
    {
        if (!vis[e->v])
        {
            vis[src] = true;
            allPaths(e->v, dest, vis, gp, path + to_string(e->v));
            vis[src] = false;
        }
    }
    return;
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
    int src, dest;
    cin >> src >> dest;
    vector<bool> vis(n, false);
    vis[src] = true;
    allPaths(src, dest, vis, gp, to_string(src));
    // write your code here
}
