#include <iostream>
#include <vector>
#define ll long long
using namespace std;

bool isValid(string &a, string &b, string &c, vector<int> &code)
{
    // ll x = stoll(a);
    // ll y = stoll(b);
    // ll z = stoll(c);
    // return (x + y == z);
    int carry = 0;
    int i = a.size(), j = b.size(), k = c.size();
    while (i >= 0 && j >= 0)
    {
        int sum = code[a[i] - 'a'] + code[b[j] - 'a'] + carry;
        if ((k == -1) || (sum % 10 != code[c[k] - 'a']))
            return false;
        carry = sum / 10;
        i--, j--, k--;
    }
    while (i >= 0)
    {
        int sum = code[a[i] - 'a'] + carry;
        if (k == -1 || sum % 10 != c[k])
            return false;
        carry = sum / 10;
        i--, k--;
    }
    while (j >= 0)
    {
        int sum = code[b[j] - 'a'] + carry;
        if (k == -1 || sum % 10 != c[k])
            return false;
        carry = sum / 10;
        j--, k--;
    }
    return true;
}

ll tonum(string &a, vector<int> &code)
{
    ll ans = 0;
    for(char c : a)
        if(code[c-'a'] != -1)
            ans = ans*10 + code[c-'a'];
    return ans;
}

void cryptarithmetic(int idx, string &a, string &b, string &c, string &s, int used, vector<bool> &vis, vector<int> &code)
{
    if (idx == s.size())
    {
        ll x = tonum(a, code);
        ll y = tonum(b, code);
        ll z = tonum(c, code);
        if(isValid(a, b, c, code))
        // if(x + y == z)
        {
            // cout << idx << endl;
            for (int i = 0; i < 26; i++)
            {
                if (code[i] != -1)
                {
                    cout << char(i + 'a') << "-" << code[i] << " ";
                }
            }
            cout << "\n";
        }
        return;
    }

    for (int x = 0; x <= 9; x++)
    {
        if (!(used & (1 << x)))
        // if(!vis[x])
        {
            used ^= (1 << x);
            vis[x] = true;
            code[s[idx] - 'a'] = x;
            cryptarithmetic(idx + 1, a, b, c, s, used, vis, code);
            used ^= (1 << x);
            vis[x] = false;
            code[s[idx] - 'a'] = -1;
        }
    }
}

int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    string uni = "";
    vector<bool> vis(26, false);
    for (char x : a)
    {
        if (!vis[x - 'a'])
            uni += x;
        vis[x - 'a'] = true;
    }
    for (char x : b)
    {
        if (!vis[x - 'a'])
            uni += x;
        vis[x - 'a'] = true;
    }
    for (char x : c)
    {
        if (!vis[x - 'a'])
            uni += x;
        vis[x - 'a'] = true;
    }
    // cout << uni << endl;
    vector<int> code(26, -1);
    vector<bool> vis2(10);
    cryptarithmetic(0, a, b, c, uni, 0, vis2, code);
}