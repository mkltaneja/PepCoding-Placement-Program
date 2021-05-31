#include <iostream>
#include <vector>
using namespace std;

class trie
{
public:
    vector<trie *> child;
    bool wordEnd;
    trie()
    {
        this->child.assign(26, nullptr);
        this->wordEnd = false;
    }

    void insert(trie *t, string &word)
    {
        for (char c : word)
        {
            if (t->child[c - 'a'] == nullptr)
                t->child[c - 'a'] = new trie();
            t = t->child[c - 'a'];
        }
        t->wordEnd = true;
    }
};
trie *t = new trie();

void sentences(int i, string &s, string ssf)
{
    if (i == s.size())
    {
        cout << ssf << "\n";
        return;
    }

    string tmps = "";
    trie *tmpt = t;
    for (int j = i; j < s.size(); j++)
    {
        tmps += s[j];
        if (tmpt->child[s[j] - 'a'])
            tmpt = tmpt->child[s[j] - 'a'];
        else
            return;
        if (tmpt->wordEnd)
            sentences(j + 1, s, ssf + tmps + " ");
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
        t->insert(t, words[i]);
    }
    string s;
    cin >> s;
    sentences(0, s, "");
}