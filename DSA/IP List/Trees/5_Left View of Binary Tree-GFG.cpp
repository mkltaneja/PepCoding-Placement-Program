vector<int> leftView(Node *root)
{
    if (!root)
        return {};
    vector<int> ans;
    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        int sz = que.size();
        while (sz--)
        {
            Node *node = que.front();
            que.pop();
            if (sz == 0)
                ans.push_back(node->data);
            if (node->right)
                que.push(node->right);
            if (node->left)
                que.push(node->left);
        }
    }
    return ans;
}