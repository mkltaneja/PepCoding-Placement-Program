
// APPROACH 1 (Using Stack) --> Time - O(n), Space - O(n)

string finalstr(string &s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c != '#')
            st.push(c);
        else if (!st.empty())
            st.pop();
    }
    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

bool backspaceCompare(string s, string t)
{
    string ss = finalstr(s);
    string tt = finalstr(t);

    return ss == tt;
}

// APPROACH 2 (2 Pointer) --> Time - <O(n), Space - O(1)
