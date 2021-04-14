#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void stockspan(int n, vector<int> &arr)
{
    stack<int> st;
    vector<int> ans(n);
    st.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (st.top() != -1 && arr[i] >= arr[st.top()])
            st.pop();
        ans[i] = i - st.top();
        st.push(i);
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

    stockspan(n, arr);
}