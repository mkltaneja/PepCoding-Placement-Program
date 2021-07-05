
#define mod 1000000007
void findsum(Node *node1, Node *node2, long long &ans)
{
    if (!node1 || !node2)
        return;
    // cout<<(node1->data)<<", "<<(node2->data)<<endl;
    ans += (node1->data % mod) * (node2->data % mod) % mod;

    findsum(node1->left, node2->right, ans);
    findsum(node1->right, node2->left, ans);
}

long long imgMultiply(Node *root)
{
    long long ans = 0;
    findsum(root->left, root->right, ans);
    return ((ans % mod) + (((root->data % mod) * (root->data % mod)) % mod)) % mod;
}