
// APPROACH 1 (Moore Voting Algorithm) --> O(n*k) time; O(k-1) space

int countOccurence(int arr[], int n, int k)
{
    vector<pair<int, int>> cand(k - 1, {0, 0});
    for (int i = 0; i < n; i++)
    {
        bool f = false;
        for (int j = 0; j < k - 1; j++)
        {
            if (arr[i] == cand[j].first)
            {
                cand[j].second++;
                f = true;
                break;
            }
        }
        if (f)
            continue;
        for (int j = 0; j < k - 1; j++)
        {
            if (cand[j].second == 0)
            {
                cand[j].first = arr[i];
                cand[j].second = 1;
                f = true;
                break;
            }
        }
        if (f)
            continue;
        for (int j = 0; j < k - 1; j++)
            cand[j].second--;
    }
    int ans = 0;
    for (int i = 0; i < k - 1; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (arr[j] == cand[i].first)
                cnt++;
        if (cnt > n / k)
            ans++;
    }
    return ans;
}

// APPROACH 2 (Using Hashmap) --> O(n) time; O(n) space

int countOccurence(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;
    int ans = 0;
    for (auto p : m)
        if (p.second > n / k)
            ans++;
    return ans;
    // Your code here
}