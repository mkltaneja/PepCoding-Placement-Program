
// METHOD 1
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;
#define f first
#define s second

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node *construct(vector<int> &arr)
{
    Node *root = new Node(arr[0], nullptr, nullptr);
    pair<Node *, int> rtp = {root, 1};

    stack<pair<Node *, int>> st;
    st.push(rtp);

    int idx = 0;
    while (st.size() > 0)
    {
        pair<Node *, int> tp = st.top();
        if (tp.s == 1)
        {
            idx++;
            st.top().s++;
            if (arr[idx] != -1)
            {
                tp.f->left = new Node(arr[idx], nullptr, nullptr);
                pair<Node *, int> lp = {tp.f->left, 1};
                st.push(lp);
            }
            else
                tp.f->left = nullptr;
        }
        else if (tp.s == 2)
        {
            idx++;
            st.top().s++;
            if (arr[idx] != -1)
            {
                tp.f->right = new Node(arr[idx], nullptr, nullptr);
                pair<Node *, int> rp = {tp.f->right, 1};
                st.push(rp);
            }
            else
                tp.f->right = nullptr;
        }
        else
            st.pop();
    }

    return root;
}

void display(Node *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += node->left == nullptr ? "." : to_string(node->left->data) + "";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right == nullptr ? "." : to_string(node->right->data) + "";
    cout << str << endl;

    display(node->left);
    display(node->right);
}

bool bst = true;
pair<int, int> isBST(Node *node)
{
    if (!node)
        return {INT_MAX, INT_MIN}; // {mini, maxi}

    pair<int, int> ltree = isBST(node->left);
    pair<int, int> rtree = isBST(node->right);

    if (!bst || node->data < ltree.s || node->data > rtree.f)
    {
        bst = false;
        return {INT_MAX, INT_MIN};
    }
    int maxi = max(node->data, max(ltree.s, rtree.s));
    int mini = min(node->data, min(ltree.f, rtree.f));

    return {mini, maxi};
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        if (a == "n")
            arr[i] = -1;
        else
            arr[i] = stoi(a);
    }

    Node *root = construct(arr);

    isBST(root);
    cout << (boolalpha) << bst << endl;
    // write your code here
}

// METHOD 2

#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;
#define f first
#define s second

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node *construct(vector<int> &arr)
{
    Node *root = new Node(arr[0], nullptr, nullptr);
    pair<Node *, int> rtp = {root, 1};

    stack<pair<Node *, int>> st;
    st.push(rtp);

    int idx = 0;
    while (st.size() > 0)
    {
        pair<Node *, int> tp = st.top();
        if (tp.s == 1)
        {
            idx++;
            st.top().s++;
            if (arr[idx] != -1)
            {
                tp.f->left = new Node(arr[idx], nullptr, nullptr);
                pair<Node *, int> lp = {tp.f->left, 1};
                st.push(lp);
            }
            else
                tp.f->left = nullptr;
        }
        else if (tp.s == 2)
        {
            idx++;
            st.top().s++;
            if (arr[idx] != -1)
            {
                tp.f->right = new Node(arr[idx], nullptr, nullptr);
                pair<Node *, int> rp = {tp.f->right, 1};
                st.push(rp);
            }
            else
                tp.f->right = nullptr;
        }
        else
            st.pop();
    }

    return root;
}

void display(Node *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += node->left == nullptr ? "." : to_string(node->left->data) + "";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right == nullptr ? "." : to_string(node->right->data) + "";
    cout << str << endl;

    display(node->left);
    display(node->right);
}

bool bst = true;
pair<int, int> isBST(Node *node)
{
    if (!node)
        return {INT_MAX, INT_MIN}; // {mini, maxi}

    pair<int, int> ltree = isBST(node->left);
    pair<int, int> rtree = isBST(node->right);

    if (!bst || node->data < ltree.s || node->data > rtree.f)
    {
        bst = false;
        return {INT_MAX, INT_MIN};
    }
    int maxi = max(node->data, max(ltree.s, rtree.s));
    int mini = min(node->data, min(ltree.f, rtree.f));

    return {mini, maxi};
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        if (a == "n")
            arr[i] = -1;
        else
            arr[i] = stoi(a);
        // cout<<arr[i]<<endl;
    }

    Node *root = construct(arr);

    isBST(root);
    cout << (boolalpha) << bst << endl;
    // write your code here
}
