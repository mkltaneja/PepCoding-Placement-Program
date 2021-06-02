
// APPROACH 1 (Using map for dynamically adding the vertical level; and multiset for automatically sorting the same horizotal and vertical level nodes)

#define f first
#define s second
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, vector<int>> mp;
    queue<pair<TreeNode *, int>> que;
    que.push({root, 0});
    mp[0].push_back(root->val);
    while (!que.empty())
    {
        int sz = que.size();
        unordered_map<int, multiset<int>> tmp;
        while (sz--)
        {
            auto top = que.front();
            que.pop();
            if (top.f->left)
            {
                que.push({top.f->left, top.s - 1});
                tmp[top.s - 1].insert(top.f->left->val);
            }
            if (top.f->right)
            {
                que.push({top.f->right, top.s + 1});
                tmp[top.s + 1].insert(top.f->right->val);
            }
        }
        for (auto p : tmp)
            for (int x : p.s)
                mp[p.f].push_back(x);
    }
    vector<vector<int>> ans;
    for (auto p : mp)
        ans.push_back(p.s);

    return ans;
}