
bool sameFreq(string s)
{
    vector<int> map(26);
    for (char c : s)
        map[c - 'a']++;
    unordered_set<int> mc;
    for (int x : map)
        if (x)
            mc.insert(x);
    if (mc.size() > 2)
        return false;
    if (mc.size() == 1)
        return true;

    int x = *mc.begin();
    int y = *(++mc.begin());
    if (x == 1 || y == 1 || abs(x - y) <= 1)
        return true;
    return false;
}