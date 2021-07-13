
string findOrder(string dict[], int N, int K)
{
    unordered_map<char, set<char>> gp;
    unordered_map<char, int> inDeg;

    for (int i = 0; i < N; i++)
        for (char c : dict[i])
            inDeg[c] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        string word1 = dict[i];
        string word2 = dict[i + 1];
        int x = 0, y = 0;
        while (x < word1.size() && y < word2.size() && word1[x] == word2[y])
            x++, y++;
        if (x != word1.size() && y != word2.size())
        {
            if (!gp[word1[x]].count(word2[y]))
            {
                gp[word1[x]].insert(word2[y]);
                inDeg[word2[y]]++;
            }
        }
        else if (y == word2.size())
            return "";
    }

    queue<char> que;
    for (auto p : inDeg)
        if (p.second == 0)
            que.push(p.first);

    string ans;
    while (!que.empty())
    {
        char u = que.front();
        que.pop();
        ans += u;
        for (char v : gp[u])
            if (--inDeg[v] == 0)
                que.push(v);
    }
    // cout<<ans<<endl;
    return (ans.size() == gp.size()) ? ans : "";
}