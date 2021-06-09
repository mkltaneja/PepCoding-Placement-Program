
#define f first
#define s second

int countnodes(int u, vector<vector<int>> &gp, vector<int> &subnodes, vector<bool> &vis)
{
    vis[u] = true;
    int count = 0;
    for (int v : gp[u])
        if (!vis[v])
            count += countnodes(v, gp, subnodes, vis);
    return subnodes[u] = count + 1;
}

int findDist(int u, vector<vector<int>> &gp)
{
    vector<bool> vis(gp.size(), false);
    vis[u] = true;

    queue<pair<int, int>> que;
    que.push({u, 0});
    int dist0 = 0;

    while (!que.empty())
    {
        auto p = que.front();
        que.pop();

        dist0 += p.s;

        for (int v : gp[p.f])
        {
            if (!vis[v])
            {
                vis[v] = true;
                que.push({v, p.s + 1});
            }
        }
    }
    return dist0;
}

void findDistAll(int dist0, int n, vector<vector<int>> &gp, vector<int> &subnodes, vector<int> &ans)
{
    vector<bool> vis(gp.size(), false);
    vis[0] = true;

    queue<pair<int, int>> que;
    que.push({0, dist0});

    while (!que.empty())
    {
        auto p = que.front();
        que.pop();

        ans[p.f] = p.s;
        for (int v : gp[p.f])
        {
            if (vis[v])
                continue;
            vis[v] = true;
            int distv = p.s - subnodes[v] + (n - subnodes[v]);
            que.push({v, distv});
        }
    }
}

vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges)
{
    vector<vector<int>> gp(N);

    for (int i = 0; i < edges.size(); i++)
    {
        gp[edges[i][0]].push_back(edges[i][1]);
        gp[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> subnodes(N);
    vector<bool> vis(N, false);
    countnodes(0, gp, subnodes, vis);

    int dist0 = findDist(0, gp);

    vector<int> ans(N);
    findDistAll(dist0, N, gp, subnodes, ans);

    return ans;
}