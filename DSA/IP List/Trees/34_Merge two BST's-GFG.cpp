
Node *addNode(Node *t1, Node *t2)
{
    if (!t1 || !t2)
        return t1 ? t1 : t2;

    Node *h1 = t1->right;
    Node *h2 = t2->right;

    h1->left = t2;
    t2->right = h1;

    t1->right = h2;
    h2->left = t1;

    return t2;
}

Node *BSTtoCDLL(Node *root)
{
    if (!root)
        return nullptr;

    Node *lt = BSTtoCDLL(root->left);
    Node *rt = BSTtoCDLL(root->right);

    root->left = root;
    root->right = root;

    if (!lt && !rt)
        return root;

    Node *tail1 = addNode(lt, root);
    Node *tail2 = addNode(tail1, rt);

    return tail2;
}

Node *mergeLists(Node *l1, Node *l2)
{
    Node *lans = new Node(-1), *lroot = lans;
    while (l1 && l2)
    {
        if (l1->data < l2->data)
        {
            lans->right = new Node(l1->data);
            lans = lans->right;
            l1 = l1->right;
        }
        else
        {
            lans->right = new Node(l2->data);
            lans = lans->right;
            l2 = l2->right;
        }
    }
    while (l1)
    {
        lans->right = new Node(l1->data);
        lans = lans->right;
        l1 = l1->right;
    }
    while (l2)
    {
        lans->right = new Node(l2->data);
        lans = lans->right;
        l2 = l2->right;
    }
    return lroot->right;
}

public:
//Function to return a list of integers denoting the node
//values of both the BST in a sorted order.
vector<int> merge(Node *root1, Node *root2)
{
    Node *l1 = BSTtoCDLL(root1);
    Node *ll1 = l1->right;
    l1->right = nullptr;

    Node *l2 = BSTtoCDLL(root2);
    Node *ll2 = l2->right;
    l2->right = nullptr;

    Node *list = mergeLists(ll1, ll2);

    vector<int> ans;
    while (list)
    {
        ans.push_back(list->data);
        list = list->right;
    }
    return ans;
}