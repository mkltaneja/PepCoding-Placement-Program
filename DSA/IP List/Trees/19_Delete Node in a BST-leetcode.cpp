
TreeNode *deleteKey(TreeNode *node)
{
    TreeNode *rootans;
    if (!node->left && !node->right)
        rootans = nullptr;
    else if (!node->left || !node->right)
        rootans = (node->left) ? node->left : node->right;
    else
    {
        TreeNode *nodep1 = node->left;
        while (nodep1->right)
            nodep1 = nodep1->right;
        nodep1->right = node->right;
        rootans = node->left;
    }
    delete node;
    return rootans;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return root;

    if (root->val > key)
        root->left = deleteNode(root->left, key);
    else if (root->val < key)
        root->right = deleteNode(root->right, key);
    else
        root = deleteKey(root);
    return root;
}