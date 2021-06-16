
// APPROACH 1 (Standard Approach) --> O(n)

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
        return nullptr;

    if (root->val == p->val || root->val == q->val)
        return root;

    TreeNode *lans = lowestCommonAncestor(root->left, p, q);
    TreeNode *rans = lowestCommonAncestor(root->right, p, q);

    if (!lans && !rans)
        return nullptr;
    if (lans && rans)
        return root;
    return (lans) ? lans : rans;
}