#include <iostream>
#include <stack>
using namespace std;

bool has_duplicate(string &s)
{
    stack<char> st;
    for (char c : s)
    {
        // cout<<c<<endl;
        if (c == ')')
        {
            if (st.top() == '(')
                return true;
            while (st.top() != '(')
                st.pop();
            st.pop();
        }
        else
            st.push(c);
    }
    return false;
}

int main()
{
    string s;
    getline(cin, s);
    cout << (boolalpha) << has_duplicate(s);
}