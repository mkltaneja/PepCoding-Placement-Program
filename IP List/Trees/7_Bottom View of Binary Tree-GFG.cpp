
#define f first
#define s second
vector<int> bottomView(Node *root)
{
    if (!root)
        return {};
    map<int, int> mp;
    queue<pair<Node *, int>> que;
    que.push({root, 0});
    mp[0] = root->data;
    while (!que.empty())
    {
        int sz = que.size();
        while (sz--)
        {
            auto top = que.front();
            que.pop();
            if (top.f->left)
            {
                mp[top.s - 1] = top.f->left->data;
                que.push({top.f->left, top.s - 1});
            }
            if (top.f->right)
            {
                mp[top.s + 1] = top.f->right->data;
                que.push({top.f->right, top.s + 1});
            }
        }
    }
    vector<int> ans;
    for (auto p : mp)
        ans.push_back(p.s);
    return ans;
}