#include <iostream>
#include <stack>
using namespace std;

string smallestno(string &s)
{
    int n = 1;
    string ans = "";
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'd')
            st.push(n++);
        else
        {
            st.push(n++);
            while (!st.empty())
            {
                ans += to_string(st.top());
                st.pop();
            }
        }
    }
    st.push(n);
    while (!st.empty())
    {
        ans += to_string(st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << smallestno(s);
}