
// We use Bellmann Ford Algorithms to check if there is a negative weight cycle or not.
// IfThe Bellmann Ford Algorithm finds the minimum distance along with the path length
// We do exactly n-1 iterations, and ith iteration finds the minimum distance for the ith path
// So its similar to BFS
int inf = INT_MAX;
int isNegativeWeightCycle(int n, vector<vector<int>> edges)
{
    vector<int> minDist(n, inf);
    minDist[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (vector<int> edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            if (minDist[u] == inf)
                continue;
            if (minDist[u] + w < minDist[v])
                minDist[v] = minDist[u] + w;
        }
    }

    // CHECK for the nth iteration -> if any weight is updated, then definitely there is a negative cycle.
    for (vector<int> edge : edges)
    {
        int u = edge[0], v = edge[1], w = edge[2];
        if (minDist[u] == inf)
            continue;
        if (minDist[u] + w < minDist[v])
            return 1;
    }
    return 0;
}