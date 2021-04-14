
int maxSubArray(vector<int> &arr)
{
    int maxsum = INT_MIN, sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (sum < 0)
            sum = arr[i];
        else
            sum += arr[i];
        maxsum = max(maxsum, sum);
        // cout<<maxsum<<endl;
    }
    return maxsum;
}