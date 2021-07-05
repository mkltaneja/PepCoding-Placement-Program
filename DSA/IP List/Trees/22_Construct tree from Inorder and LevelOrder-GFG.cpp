

Node *build(int l, int r, int lvl[], int n, unordered_map<int, int> &mi)
{
    if (l > r)
        return nullptr;
    if (l == r)
        return new Node(lvl[0]);
    int idx = mi[lvl[0]];
    Node *node = new Node(lvl[0]);

    int lefts[idx - l];
    int rights[r - idx];
    int j = 0, k = 0;
    for (int i = 1; i < n; i++)
    {
        if (mi[lvl[i]] < mi[lvl[0]])
            lefts[j++] = lvl[i];
        else
            rights[k++] = lvl[i];
    }

    node->left = build(l, idx - 1, lefts, idx - l, mi);
    node->right = build(idx + 1, r, rights, r - idx, mi);

    return node;
}

Node *buildTree(int inorder[], int levelOrder[], int iStart, int iEnd, int n)
{
    unordered_map<int, int> mi;
    for (int i = 0; i <= iEnd; i++)
        mi[inorder[i]] = i;
    return build(0, iEnd, levelOrder, n, mi);
}