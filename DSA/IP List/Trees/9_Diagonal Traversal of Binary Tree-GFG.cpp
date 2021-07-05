
#define f first
#define s second

void dfs(int x, Node *node, map<int, vector<int>> &mp)
{
    if (!node)
        return;
    mp[x].push_back(node->data);
    dfs(x + 1, node->left, mp);
    dfs(x, node->right, mp);
}

vector<int> diagonal(Node *root)
{
    map<int, vector<int>> mp;
    dfs(0, root, mp);
    vector<int> ans;
    for (auto p : mp)
        for (int x : p.s)
            ans.push_back(x);
    return ans;
}