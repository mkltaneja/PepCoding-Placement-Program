
// APPROACH 1 (By finding Next smaller element on left starting from right) [Stack Space]

Node *buildBST(int l, int r, vector<int> &post, vector<int> &nsel)
{
    if (l > r)
        return nullptr;

    Node *root = new Node(post[r]);

    if (l == r)
        return root;

    root->left = buildBST(l, nsel[r], post, nsel);
    root->right = buildBST(nsel[r] + 1, r - 1, post, nsel);

    return root;
}

Node *constructTree(int post[], int size)
{
    vector<int> nsel(size, -1);
    stack<int> st;
    for (int i = size - 1; i >= 0; i--)
    {
        while (!st.empty() && post[i] < post[st.top()])
        {
            nsel[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        nsel[st.top()] = -1;
        st.pop();
    }
    // for(int x : nsel)
    //     cout<<x<<" ";
    // cout<<endl;

    vector<int> postv(size);
    for (int i = 0; i < size; i++)
        postv[i] = post[i];
    return buildBST(0, size - 1, postv, nsel);
}

// APPROACH 2 (Check BST Approach) [Space OPTIMIZED]

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