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

bool have_MirrorShape(Node *n1, Node *n2)
{
    if (n1->children.size() != n2->children.size())
        return false;
    int n = n1->children.size();
    for (int i = 0; i < n; i++)
        if (have_MirrorShape(n1->children[i], n2->children[n - i - 1]) == false)
            return false;
    return true;
}

bool isSymmetric(Node *node)
{
    if (have_MirrorShape(node, node))
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Node *root = construct(a);
    cout << (boolalpha) << isSymmetric(root);
}