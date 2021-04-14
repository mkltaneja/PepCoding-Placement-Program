#include <iostream>
#include <stack>
using namespace std;

bool has_duplicate(string &s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
            st.push(c);
        else
        {
            if (c == ')')
            {
                if (st.empty() || st.top() != '(')
                    return false;
                st.pop();
            }
            else if (c == ']')
            {
                if (st.empty() || st.top() != '[')
                    return false;
                st.pop();
            }
            else if (c == '}')
            {
                if (st.empty() || st.top() != '{')
                    return false;
                st.pop();
            }
        }
    }
    return st.empty();
}

int main()
{
    string s;
    getline(cin, s);
    cout << (boolalpha) << has_duplicate(s);
}