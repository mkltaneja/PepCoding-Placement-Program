
void stickedTree(Node *node)
{
    if (!node)
        return;

    Node *l = node->left;

    Node *newl = new Node(node->data);

    node->left = newl;
    newl->left = l;

    stickedTree(node->left->left);
    stickedTree(node->right);
}

void set_RandomPtrs(Node *node)
{
    if (!node)
        return;

    if (node->random)
        node->left->random = node->random->left;

    set_RandomPtrs(node->left->left);
    set_RandomPtrs(node->right);
}

Node *detatchTree(Node *node)
{
    if (!node)
        return nullptr;

    Node *root = node->left;

    root->left = detatchTree(node->left->left);
    root->right = detatchTree(node->right);

    node->left = node->left->left;

    return root;
}

/* The function should clone the passed tree and return 
       root of the cloned tree */
Node *cloneTree(Node *tree)
{
    stickedTree(tree);
    set_RandomPtrs(tree);
    return detatchTree(tree);
}