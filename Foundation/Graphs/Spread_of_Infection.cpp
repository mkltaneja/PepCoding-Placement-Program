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

int infected(int i, vector<vector<Edge *>> &gp, vector<bool> &vis, int t)
{
    int count = 1;
    queue<int> que;
    que.push(i);
    vis[i] = true;
    // cout<<t<<endl;
    while ((t ^ 1) && !que.empty())
    {
        int sz = que.size();
        while (sz--)
        {
            int tp = que.front();
            que.pop();
            for (Edge *e : gp[tp])
            {
                if (!vis[e->v])
                {
                    que.push(e->v);
                    vis[e->v] = true;
                    count++;
                }
            }
        }
        t--;
    }
    return count;
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
    int src, t;
    cin >> src >> t;

    vector<bool> vis(n, false);
    cout << infected(src, gp, vis, t) << endl;
    // write your code here
}
