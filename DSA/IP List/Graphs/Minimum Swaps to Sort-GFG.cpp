
//Function to find the minimum number of swaps required to sort the array.
int minSwaps(vector<int> &nums)
{
    int n = nums.size();
    vector<pair<int, int>> sorted(n);
    for (int i = 0; i < n; i++)
        sorted[i] = {nums[i], i};

    sort(sorted.begin(), sorted.end());
    int ans = 0;
    vector<bool> done(n, false);
    for (int i = 0; i < n; i++)
    {
        if (done[i] || sorted[i].second == i)
            continue;
        int cnt = 0, j = i;
        while (!done[j])
        {
            done[j] = true;
            cnt++;
            j = sorted[j].second;
        }
        ans += cnt - 1;
    }
    return ans;
}