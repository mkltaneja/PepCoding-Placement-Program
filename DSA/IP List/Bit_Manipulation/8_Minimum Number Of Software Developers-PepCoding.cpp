
// METHOD 1 (Recursively)=============================================================

#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
void subseq(int i, int x, int tar, vector<int> &arr, vector<int> tmp)
{
    if (i == arr.size())
    {
        if ((x == tar) && (ans.empty() || tmp.size() <= ans.size()))
            ans = tmp;
        return;
    }

    tmp.push_back(i);
    subseq(i + 1, (x | arr[i]), tar, arr, tmp);
    tmp.pop_back();

    subseq(i + 1, x, tar, arr, tmp);
}

int main()
{
    int n, m;
    cin >> n;
    unordered_map<string, int> map;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        map[x] = i;
    }
    cin >> m;
    vector<int> arr(m);
    for (int i = 0; i < m; i++)
    {
        int tot;
        cin >> tot;
        int fskill = 0;
        for (int j = 0; j < tot; j++)
        {
            string x;
            cin >> x;
            fskill |= (1 << map[x]);
        }
        arr[i] = fskill;
    }

    subseq(0, 0, (1 << n) - 1, arr, {});

    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << ", ";
    }
    cout << "]";
}

// METHOD 2 (Iteratively)========================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    unordered_map<string, int> map;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        map[x] = i;
    }
    cin >> m;
    vector<int> arr(m);
    for (int i = 0; i < m; i++)
    {
        int tot;
        cin >> tot;
        int fskill = 0;
        for (int j = 0; j < tot; j++)
        {
            string x;
            cin >> x;
            fskill |= (1 << map[x]);
        }
        arr[i] = fskill;
    }

    vector<int> ans;
    
    for(int x = 0; x < (1 << m); x++)
    {
        int totskills = 0;
        vector<int> tmp;
        for(int i = 0; i < m; i++)
        {
            if(x & (1 << i))
            {
                totskills |= arr[i];
                tmp.push_back(i);
            }
        }
        if(totskills == (1 << n)-1 && (ans.empty() || tmp.size() <= ans.size()))
            ans = tmp;
    }

    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << ", ";
    }
    cout << "]";
}