int findMaxDiff(int A[], int n)
    {
        stack<int> st;
        int ans = 0;
        for(int i = 0; i <= n; i++)
        {
            int x = (i == n)? 0 : A[i];
            while(!st.empty() && x < A[st.top()])
            {
                int top = A[st.top()];
                st.pop();
                if(!st.empty() && top == A[st.top()])
                    continue;
                ans = max(ans, (st.empty()? x : abs(A[st.top()] - x)));
            }
            st.push(i);
        }
        return ans;
    }