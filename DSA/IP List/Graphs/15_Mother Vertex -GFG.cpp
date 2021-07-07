
void dfs1(int u, stack<int> &st, vector<bool> &vis, vector<int> *gp)
{
    vis[u] = true;
    for (int v : gp[u])
        if (!vis[v])
            dfs1(v, st, vis, gp);
    st.push(u);
}

void dfs2(int u, vector<bool> &vis, vector<int> *gp)
{
    vis[u] = true;
    for (int v : gp[u])
        if (!vis[v])
            dfs2(v, vis, gp);
}

int findMotherVertex(int V, vector<int> adj[])
{
    stack<int> st;
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++)
        if (!vis[i])
            dfs1(i, st, vis, adj);
    vis.assign(V, false);
    int cnt = 0;
    int ans = -1;
    while (!st.empty())
    {
        int tp = st.top();
        st.pop();
        if (!vis[tp])
        {
            if (++cnt > 1)
                return -1;
            ans = tp;
            dfs2(tp, vis, adj);
        }
    }
    return ans;
}