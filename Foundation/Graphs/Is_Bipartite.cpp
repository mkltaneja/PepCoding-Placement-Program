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

bool isBipartite(int i, vector<vector<Edge *>> &gp, vector<int> &vis)
{
    queue<int> que;
    que.push(i);
    vis[i] = 0;
    while (!que.empty())
    {
        int tp = que.front();
        que.pop();
        for (Edge *e : gp[tp])
        {
            if (vis[e->v] == -1)
            {
                que.push(e->v);
                vis[e->v] = (vis[tp] + 1) % 2;
            }
            else if (vis[e->v] == vis[tp])
                return false;
        }
    }
    return true;
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

    vector<int> vis(n, -1);
    bool f = true;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == -1)
        {
            if (!isBipartite(i, gp, vis))
            {
                f = false;
                break;
            }
        }
    }
    if (f)
        cout << "true";
    else
        cout << "false";
    // write your code here
}
