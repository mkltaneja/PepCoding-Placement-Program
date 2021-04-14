#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Node 
{
public:
    Node(){}
    int data;
    vector<Node*> children;
};

void display(Node* node) 
{
    string str = node->data + " -> ";
    for (Node* child : node->children) {
      str += child->data + ", ";
    }
    str += ".";
    cout<<str<<endl;
    
    for (Node* child : node->children) 
    {
      display(child);
    }
}

Node* construct(vector<int> &arr) 
{
    Node* root = nullptr;
    
    stack<Node*> st;
    for (int i = 0; i < arr.size(); i++) 
    {
      if (arr[i] == -1)
        st.pop();
      else 
      {
        Node* t = new Node();
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

int size(Node* node)
{
    if(!node)
        return 0;
    int count = 0;
    for(Node* n : node->children)
        count += size(n);
    return count+1;
// write your code here
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    Node* root = construct(arr);
    int sz = size(root);
    cout<<sz<<endl;
    // display(root);
}
