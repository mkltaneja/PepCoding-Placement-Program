
// APPROACH 1 (Finding pair for every node) --> O(n^2)

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

bool findpair(Node *node, int tar)
{
    if (!node)
        return false;
    if (node->data == tar)
        return true;
    if (node->data > tar)
        return findpair(node->left, tar);
    else if (node->data < tar)
        return findpair(node->right, tar);
}

void pairsum(Node *node, Node *root, int tar)
{
    if (!node)
        return;
    pairsum(node->left, root, tar);
    int x = node->data;
    int y = tar - node->data;
    if (y > x && findpair(root, y))
        cout << x << " " << y << endl;
    pairsum(node->right, root, tar);
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

    int data;
    cin >> data;
    pairsum(root, root, data);
    // write your code here
}

// APPROACH 2 (inorder traversal to make a sorted array then check by 2 pointer approach) --> O(n)

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

void inorder(Node *node, vector<int> &vals)
{
    if (!node)
        return;
    inorder(node->left, vals);
    vals.push_back(node->data);
    inorder(node->right, vals);
}

void pairsum(Node *node, int tar)
{
    vector<int> vals;
    inorder(node, vals);
    int i = 0, j = vals.size() - 1;
    while (i < j)
    {
        int sum = vals[i] + vals[j];
        if (sum == tar)
            cout << vals[i++] << " " << vals[j--] << endl;
        else if (sum < tar)
            i++;
        else
            j--;
    }
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

    int data;
    cin >> data;
    pairsum(root, data);
    // write your code here
}
