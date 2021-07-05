
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

Node *treeToCDLL(Node *root)
{
    if (!root)
        return nullptr;

    Node *lt = treeToCDLL(root->left);
    Node *rt = treeToCDLL(root->right);

    root->left = root;
    root->right = root;
    if (!lt && !rt)
        return root;

    Node *tail1 = addNode(lt, root);
    Node *tail2 = addNode(tail1, rt);

    return tail2;
}

//Function to convert binary tree into circular doubly linked list.
Node *bTreeToCList(Node *root)
{
    return treeToCDLL(root)->right;
}