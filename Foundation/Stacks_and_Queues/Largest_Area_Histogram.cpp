#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int maxarea_histogram(int n, vector<int> &arr)
{
    stack<int> st;
    int maxarea = 0, i = 0;
    for (; i < n; i++)
    {
        // cout<<arr[i]<<":";
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            int tp = st.top();
            st.pop();
            int area = arr[tp] * (st.empty() ? i : (i - st.top() - 1));
            maxarea = max(maxarea, area);
            // cout<<area<<" ";
        }
        // cout<<" --> "<<maxarea<<endl;
        st.push(i);
    }
    while (!st.empty())
    {
        int tp = st.top();
        st.pop();
        int area = arr[tp] * (st.empty() ? i : (i - st.top() - 1));
        maxarea = max(maxarea, area);
    }

    return maxarea;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxarea_histogram(n, arr);
}