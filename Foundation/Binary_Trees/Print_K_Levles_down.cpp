
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <queue>
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

// APPROACH 1 (BFS)=================================================================
vector<int> kdown(Node *node, int k)
{
    vector<int> ans;
    queue<Node *> que;
    que.push(node);
    int level = 0;
    while (!que.empty())
    {
        int sz = que.size();
        while (sz--)
        {
            Node *tp = que.front();
            que.pop();
            if (level == k)
                ans.push_back(tp->data);
            else
            {
                if (tp->left)
                    que.push(tp->left);
                if (tp->right)
                    que.push(tp->right);
            }
        }
        level++;
        if (!ans.empty())
            return ans;
    }
    return ans;
}

// APPROACH 2 (DFS)======================================================================
void kdown(Node *node, int k)
{
    if (!node)
        return;
    if (k == 0)
    {
        cout << node->data << endl;
        return;
    }
    kdown(node->left, k - 1);
    kdown(node->right, k - 1);
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

    int k;
    cin >> k;
    vector<int> ans = kdown(root, k);
    for (int x : ans)
        cout << x << endl;
}
