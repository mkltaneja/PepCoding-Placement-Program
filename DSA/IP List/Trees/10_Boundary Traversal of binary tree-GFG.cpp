
void leftboundry(Node *node, vector<int> &arr)
{
    while (node && (node->left || node->right))
    {
        arr.push_back(node->data);
        if (!node->left)
            node = node->right;
        else
            node = node->left;
    }
}
void rightboundry(Node *node, vector<int> &arr)
{
    while (node && (node->left || node->right))
    {
        arr.push_back(node->data);
        if (!node->right)
            node = node->left;
        else
            node = node->right;
    }
}
void leafnodes(Node *node, vector<int> &arr)
{
    if (!node)
        return;
    if (!node->left && !node->right)
    {
        arr.push_back(node->data);
        return;
    }
    leafnodes(node->left, arr);
    leafnodes(node->right, arr);
}

vector<int> printBoundary(Node *root)
{
    vector<int> ans;
    ans.push_back(root->data);
    vector<int> left, right, leaves;
    leftboundry(root->left, left);
    rightboundry(root->right, right);
    leafnodes(root, leaves);
    reverse(right.begin(), right.end());
    for (int x : left)
        ans.push_back(x);
    for (int x : leaves)
        ans.push_back(x);
    for (int x : right)
        ans.push_back(x);

    return ans;
}