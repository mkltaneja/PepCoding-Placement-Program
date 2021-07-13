
// Topological Sort uses Kahn's Algorithm
// It is applicalble for Directed Acyclic Graph
// Time Complexity --> O(V + E)

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> inDeg(V);
    for (int i = 0; i < V; i++)
        for (int v : adj[i])
            inDeg[v]++;

    vector<int> ans;
    queue<int> que;
    for (int i = 0; i < V; i++)
        if (inDeg[i] == 0)
            que.push(i);

    while (!que.empty())
    {
        int tp = que.front();
        que.pop();
        ans.push_back(tp);

        for (int v : adj[tp])
            if (--inDeg[v] == 0)
                que.push(v);
    }
    return ans;
}