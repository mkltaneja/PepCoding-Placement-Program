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

void bfs(int src, vector<vector<Edge *>> &gp)
{
    queue<pair<int, string>> que;
    que.push({src, to_string(src)});
    vector<bool> vis(gp.size(), false);
    vis[src] = true;
    while (!que.empty())
    {
        auto p = que.front();
        que.pop();
        cout << p.first << "@" << p.second << endl;
        for (Edge *e : gp[p.first])
        {
            if (!vis[e->v])
            {
                vis[e->v] = true;
                que.push({e->v, p.second + to_string(e->v)});
            }
        }
    }
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
    int src;
    cin >> src;
    bfs(src, gp);
    // write your code here
}
