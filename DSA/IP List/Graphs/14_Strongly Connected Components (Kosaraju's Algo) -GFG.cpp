
// Strongly Connected Components is Connected Components in the directed graph
// Here we can't just do DFS and find answer, but we have to find the problematic edges (Edges, separating the components)
// Time Complexity of SCC --> O(V+E)
// It uses Kosaraju algorithm

void dfs1(int u, vector<int> gp[], stack<int> &st, vector<bool> &vis)
{
    vis[u] = true;
    for (int v : gp[u])
        if (!vis[v])
            dfs1(v, gp, st, vis);

    st.push(u);
}

vector<vector<int>> reverse(int n, vector<int> gp[])
{
    vector<vector<int>> ngp(n);
    for (int i = 0; i < n; i++)
        for (int v : gp[i])
            ngp[v].push_back(i);
    return ngp;
}

void dfs2(int u, vector<vector<int>> &gp, vector<bool> &vis)
{
    vis[u] = true;
    for (int v : gp[u])
        if (!vis[v])
            dfs2(v, gp, vis);
}

int findComps(int n, vector<vector<int>> &gp, stack<int> &st)
{
    int ans = 0;
    vector<bool> vis(n, false);
    while (!st.empty())
    {
        int tp = st.top();
        st.pop();
        if (vis[tp])
            continue;
        dfs2(tp, gp, vis);
        ans++;
    }
    return ans;
}

int kosaraju(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++)
        if (!vis[i])
            dfs1(i, adj, st, vis);

    vector<vector<int>> ngp = reverse(V, adj);

    return findComps(V, ngp, st);
}