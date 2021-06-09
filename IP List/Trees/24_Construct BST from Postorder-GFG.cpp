
Node *buildBST(int &i, int post[], long mn, long mx)
{
    if (i == -1)
        return nullptr;
    if (post[i] <= mn || post[i] >= mx)
        return nullptr;

    Node *root = new Node(post[i--]);

    root->right = buildBST(i, post, root->data, mx);
    root->left = buildBST(i, post, mn, root->data);

    return root;
}

Node *constructTree(int post[], int size)
{
    int i = size - 1;
    return buildBST(i, post, LONG_MIN, LONG_MAX);
}