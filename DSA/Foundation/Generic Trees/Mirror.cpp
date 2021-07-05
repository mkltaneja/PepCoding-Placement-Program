#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
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

    stack<Node*> st;
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

void levelorderZZ(Node *node)
{
    queue<Node *> que;
    stack<int> st;
    int x = 0;
    que.push(node);
    while (!que.empty())
    {
        int sz = que.size();
        while (sz--)
        {
            Node *n = que.front();
            que.pop();
            if (x)
                st.push(n->data);
            else
                cout << n->data << " ";
            for (Node *child : n->children)
                que.push(child);
        }
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        x = (x + 1) % 2;
        cout << endl;
    }
}

void mirror(Node *node)
{
    int n = node->children.size();
    for (int i = 0; i < n; i++)
        mirror(node->children[i]);
    reverse(node->children.begin(), node->children.end());
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node *root = construct(arr);
    display(root);
    mirror(root);
    display(root);
}
