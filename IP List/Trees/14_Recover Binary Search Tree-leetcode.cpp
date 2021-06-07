
TreeNode *prev = new TreeNode(INT_MIN), *node1 = nullptr, *node2 = nullptr;
void checkswap(TreeNode *curr)
{
    if (!curr)
        return;

    checkswap(curr->left);

    if (!node1 && curr->val < prev->val)
    {
        node1 = prev;
        node2 = curr;
    }
    else if (curr->val < prev->val)
        node2 = curr;

    prev = curr;
    checkswap(curr->right);
}

void recoverTree(TreeNode *root)
{
    TreeNode *curr = root;

    checkswap(root);

    if (node1 && node2)
        swap(node1->val, node2->val);
}