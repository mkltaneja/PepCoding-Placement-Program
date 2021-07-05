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

bool isCyclic(int i, vector<vector<Edge *>> &gp, vector<int> &vis)
{
    queue<int> que;
    que.push(i);
    vis[i] = 1;
    while (!que.empty())
    {
        int tp = que.front();
        que.pop();
        vis[tp] = 0;
        for (Edge *e : gp[tp])
        {
            if (vis[e->v] == -1)
            {
                que.push(e->v);
                vis[e->v] = 1;
            }
            else if (vis[e->v] == 1)
                return true;
        }
    }
    return false;
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
    bool f = false;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == -1)
        {
            if (isCyclic(i, gp, vis))
            {
                f = true;
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
