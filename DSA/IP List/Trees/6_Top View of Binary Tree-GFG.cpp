#define f first
#define s second
vector<int> topView(Node *root)
{
    if (!root)
        return {};
    map<int, int> mp;
    int lmost = 0, rmost = 0;
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
                if (top.s - 1 < lmost)
                {
                    lmost = top.s - 1;
                    mp[top.s - 1] = top.f->left->data;
                }
                que.push({top.f->left, top.s - 1});
            }
            if (top.f->right)
            {
                if (top.s + 1 > rmost)
                {
                    rmost = top.s + 1;
                    mp[top.s + 1] = top.f->right->data;
                }
                que.push({top.f->right, top.s + 1});
            }
        }
    }
    vector<int> ans;
    for (auto p : mp)
        ans.push_back(p.s);
    return ans;
}