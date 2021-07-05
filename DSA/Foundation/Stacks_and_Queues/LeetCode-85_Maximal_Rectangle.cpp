
int maxarea_histogram(int i, int m, vector<vector<int>> &arr)
{
    int maxarea = 0;
    stack<int> st;
    int j = 0;
    for (; j < m; j++)
    {
        while (!st.empty() && arr[i][st.top()] >= arr[i][j])
        {
            int tp = st.top();
            st.pop();
            int area = arr[i][tp] * (st.empty() ? j : (j - st.top() - 1));
            // cout<<area<<" ";
            maxarea = max(maxarea, area);
        }
        st.push(j);
    }
    while (!st.empty())
    {
        int tp = st.top();
        st.pop();
        int area = arr[i][tp] * (st.empty() ? j : (j - st.top() - 1));
        maxarea = max(maxarea, area);
    }
    // cout<<maxarea<<endl;
    return maxarea;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    if (n == 0)
        return 0;
    int m = matrix[0].size();
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0)
            {
                arr[i][j] = matrix[i][j] - '0';
                continue;
            }
            if (matrix[i][j] == '1')
                arr[i][j] = arr[i - 1][j] + 1;
        }
    }
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < m; j++)
    //         cout<<arr[i][j]<<" ";
    //     cout<<endl;
    // }

    int maxarea = 0;
    for (int i = 0; i < n; i++)
        maxarea = max(maxarea, maxarea_histogram(i, m, arr));

    return maxarea;
}