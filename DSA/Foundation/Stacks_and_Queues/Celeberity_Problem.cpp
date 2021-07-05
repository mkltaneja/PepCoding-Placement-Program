
// APPROACH Traversing in all strings --> O(n^2)

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

string celeberity_problem(int n, vector<string> &ss)
{
    unordered_set<int> celebs;
    for (int i = 0; i < n; i++)
        celebs.insert(i);

    for (int i = 0; i < ss.size(); i++)
    {
        for (int j = 0; j < ss[i].size(); j++)
        {
            if (i == j)
                continue;
            if (ss[i][j] == '1')
                celebs.erase(i);
            else
                celebs.erase(j);
        }
    }
    string ans = "";
    for (int x : celebs)
        ans += to_string(x);
    return (celebs.size() == 0) ? "none" : ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> ss(n);
    for (int i = 0; i < n; i++)
        cin >> ss[i];
    cout << celeberity_problem(n, ss);
}

// APPROACH 2 (Using Stacks) --> O(n)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string celeberity_problem(int n, vector<string> &ss)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
        st.push(i);

    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if (ss[a][b] == '0')
            st.push(a);
        else
            st.push(b);
    }

    int potceleb = st.top();
    string ans = to_string(potceleb);

    for (int i = 0; i < n; i++)
    {
        if (i != potceleb)
        {
            if (ss[potceleb][i] == '1' || ss[i][potceleb] == '0')
            {
                ans = "none";
                break;
            }
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> ss(n);
    for (int i = 0; i < n; i++)
        cin >> ss[i];
    cout << celeberity_problem(n, ss);
}