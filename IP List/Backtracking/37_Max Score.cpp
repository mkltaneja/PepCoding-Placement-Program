#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findScore(string &word, vector<int> &value, vector<int> &cnt)
{
    int score = 0;
    vector<int> freq(26, 0);
    for (char c : word)
        freq[c - 'a']++;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > cnt[i])
            return 0;
        else
            score += value[i] * freq[i];
    }
    return score;
}

void maxscore(int idx, int n, vector<string> &words, vector<int> &cnt, vector<int> &value, int &ans, string ssf)
{
    if (idx == n)
    {
        ans = max(ans, findScore(ssf, value, cnt));
        return;
    }
    maxscore(idx + 1, n, words, cnt, value, ans, ssf + words[idx]);
    maxscore(idx + 1, n, words, cnt, value, ans, ssf);
}

int main()
{
    int n, m;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];
    cin >> m;
    vector<int> cnt(26, 0);
    while (m--)
    {
        char c;
        cin >> c;
        cnt[c - 'a']++;
    }
    vector<int> value(26);
    for (int i = 0; i < 26; i++)
        cin >> value[i];

    int ans = 0;
    maxscore(0, n, words, cnt, value, ans, "");
    cout << ans << endl;
}