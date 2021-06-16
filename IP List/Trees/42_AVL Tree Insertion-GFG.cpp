
int height(Node *node)
{
    if (!node)
        return 0;
    return node->height;
}

void updateHeight(Node *node)
{
    int lh = height(node->left);
    int rh = height(node->right);

    node->height = max(lh, rh) + 1;
}

Node *leftRotation(Node *node)
{
    Node *tmp1 = node->right;
    Node *tmp2 = tmp1->left;

    tmp1->left = node;
    node->right = tmp2;

    updateHeight(node);
    updateHeight(tmp1);

    return tmp1;
}

Node *rightRotation(Node *node)
{
    Node *tmp1 = node->left;
    Node *tmp2 = tmp1->right;

    tmp1->right = node;
    node->left = tmp2;

    updateHeight(node);
    updateHeight(tmp1);

    return tmp1;
}

/*You are required to complete this method */
Node *insertToAVL(Node *node, int data)
{
    if (!node)
        return new Node(data);

    if (node->data < data)
        node->right = insertToAVL(node->right, data);
    else if (node->data > data)
        node->left = insertToAVL(node->left, data);

    updateHeight(node);

    int hdiff = height(node->left) - height(node->right);
    if (hdiff > 1)
    {
        if (node->left->data > data) // LL
            return rightRotation(node);
        else // LR
        {
            node->left = leftRotation(node->left);
            return rightRotation(node);
        }
    }
    else if (hdiff < -1)
    {
        if (node->right->data < data) // RR
            return leftRotation(node);
        else // RL
        {
            node->right = rightRotation(node->right);
            return leftRotation(node);
        }
    }
    return node;
}