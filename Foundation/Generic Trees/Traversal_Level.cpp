#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;
};

void display(Node *node)
{
    string str = node->data + " -> ";
    for (Node *child : node->children)
    {
        str += child->data + ", ";
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

int size(Node *node)
{
    if (node == nullptr)
        return 0;
    int count = 0;
    for (Node *n : node->children)
        count += size(n);
    return count + 1;
}

void traversal(Node *node)
{
    cout << "Node Pre " << node->data << endl;
    for (Node *child : node->children)
    {
        cout << "Edge Pre " << node->data << "--" << child->data << endl;
        traversal(child);
        cout << "Edge Post " << node->data << "--" << child->data << endl;
    }
    cout << "Node Post " << node->data << endl;
}

void levelorder(Node *node)
{
    queue<Node *> que;
    que.push(node);
    while (!que.empty())
    {
        Node *n = que.front();
        que.pop();
        cout << n->data << " ";
        for (Node *child : n->children)
            que.push(child);
    }
    cout << ".";
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node *root = construct(arr);
    levelorder(root);
}
