#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void nextgreater(int n, vector<int> &arr)
{
    stack<int> st;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        ans[st.top()] = -1;
        st.pop();
    }

    for (int x : ans)
        cout << x << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    nextgreater(n, arr);
}