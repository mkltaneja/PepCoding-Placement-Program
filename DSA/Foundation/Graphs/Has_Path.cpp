#include<iostream>
#include<vector>
#include<queue>
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

void addEdge(int u, int v, int w, vector<vector<Edge*>> &gp)
{
    gp[u].push_back(new Edge(v, w));
    gp[v].push_back(new Edge(u, w));
}

bool hasPath(int src, int dest, vector<bool> &vis, vector<vector<Edge*>> &gp)
{
    if(src == dest)
        return true;
    vis[src] = true;
    for(Edge* e : gp[src])
        if(!vis[e->v])
            if(hasPath(e->v, dest, vis, gp))
                return true;
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
    int src, dest;
    cin>>src>>dest;
    vector<bool> vis(n, false);
    cout<<(boolalpha)<<hasPath(src, dest, vis, gp);
    // write your code here
}
