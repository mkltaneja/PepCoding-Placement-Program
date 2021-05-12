
// APPROACH 1 (Acquire - Release) --> O(n*m*log(n*m))
// AC

#define f first
#define s second
vector<int> smallestRange(vector<vector<int>> &nums)
{
    int k = nums.size();
    vector<pair<int, int>> mix;
    for (int i = 0; i < nums.size(); i++)
        for (int j = 0; j < nums[i].size(); j++)
            mix.push_back({nums[i][j], i});
    sort(mix.begin(), mix.end());

    unordered_map<int, int> m;
    int j = 0;
    vector<int> ans = {-1, INT_MAX - 1};
    for (int i = 0; i < mix.size(); i++)
    {
        m[mix[i].s]++;
        // cout<<mix[i].s<<" --> "<<m.size()<<endl;
        while (m.size() == k)
        {
            if ((mix[i].f - mix[j].f) < (ans[1] - ans[0]))
                ans[0] = mix[j].f, ans[1] = mix[i].f;
            if (--m[mix[j].s] == 0)
                m.erase(mix[j].s);
            j++;
        }
    }
    return ans;
}