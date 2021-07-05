#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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

int minw = INT_MAX;
int maxw = INT_MIN;
int floorw = INT_MIN;
int ceilw = INT_MAX;
string minp, maxp, floorp, ceilp;
priority_queue<pair<int, string>> pq;

void allPaths(int src, int dest, int cri, vector<bool> &vis, vector<vector<Edge *>> &gp, string path, int cost)
{
    if (src == dest)
    {
        if (cost < minw)
        {
            minw = cost;
            minp = path;
        }
        if (cost > maxw)
        {
            maxw = cost;
            maxp = path;
        }
        if (cost < cri)
        {
            if (cost > floorw)
            {
                floorw = cost;
                floorp = path;
            }
        }
        if (cost > cri)
        {
            if (cost < ceilw)
            {
                ceilw = cost;
                ceilp = path;
            }
        }
        pq.push({cost, path});
        return;
    }
    for (Edge *e : gp[src])
    {
        if (!vis[e->v])
        {
            vis[src] = true;
            allPaths(e->v, dest, cri, vis, gp, path + to_string(e->v), cost + e->w);
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
    int src, dest, cri, k;
    cin >> src >> dest >> cri >> k;
    vector<bool> vis(n, false);
    vis[src] = true;
    allPaths(src, dest, cri, vis, gp, to_string(src), 0);

    int kk = k;
    while (--kk)
        pq.pop();
    cout << "Smallest Path = " << minp << "@" << minw << endl;
    cout << "Largest Path = " << maxp << "@" << maxw << endl;
    cout << "Just Larger Path than " << cri << " = " << ceilp << "@" << ceilw << endl;
    cout << "Just Smaller Path than " << cri << " = " << floorp << "@" << floorw << endl;
    cout << k << "th largest path = " << pq.top().second << "@" << pq.top().first << endl;
    // write your code here
}
