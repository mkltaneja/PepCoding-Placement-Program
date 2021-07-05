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

string pred = "Not found";
string succ = "Not found";
int state = 0;
void predsucc(Node *node, int val)
{
    if (!node)
        return;
    if (state == 1)
    {
        succ = to_string(node->data);
        state++;
    }
    if (node->data == val)
        state++;
    if (state == 0)
        pred = to_string(node->data);
    for (Node *child : node->children)
        predsucc(child, val);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int val;
    cin >> val;

    Node *root = construct(a);
    predsucc(root, val);
    cout << "Predecessor = " << pred << "\nSuccessor = " << succ;
}