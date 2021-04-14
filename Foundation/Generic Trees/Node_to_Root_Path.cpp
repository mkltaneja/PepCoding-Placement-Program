#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;
};

void display(Node *node)
{
    string str = to_string(node->data) + " -> ";
    for (Node *child : node->children)
    {
        str += to_string(child->data) + ", ";
    }
    str += ".";
    cout << str << endl;

    for (Node *child : node->children)
    {
        display(child);
    }
}

Node *construct(vector<int> &arr)
{
    Node *root = nullptr;

    stack<Node *> st;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == -1)
            st.pop();
        else
        {
            Node *t = new Node();
            t->data = arr[i];

            if (st.size() > 0)
                st.top()->children.push_back(t);
            else
                root = t;

            st.push(t);
        }
    }

    return root;
}

bool find(Node *node, int val)
{
    if (!node)
        return false;
    if (node->data == val)
        return true;

    for (Node *child : node->children)
        if (find(child, val))
            return true;
    return false;
}

vector<int> NodeToRootPath(Node *node, int val)
{
    if (!node)
        return {};
    if (node->data == val)
        return {val};
    for (Node *child : node->children)
    {
        vector<int> path = NodeToRootPath(child, val);
        if (path.size() > 0)
        {
            path.push_back(node->data);
            return path;
        }
    }
    return {};
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node *root = construct(arr);
    int val;
    cin >> val;

    vector<int> path = NodeToRootPath(root, val);
    int m = path.size();
    cout << "[";
    for (int i = 0; i < m - 1; i++)
        cout << path[i] << ", ";
    if (m != 0)
        cout << path[m - 1] << "]";
    else
        cout << "]";
}
