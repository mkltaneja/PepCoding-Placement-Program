bool hasArrayTwoCandidates(int arr[], int n, int x)
{
    sort(arr, arr + n);
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] == x)
            return true;
        if (arr[i] + arr[j] < x)
            i++;
        else
            j--;
    }
    return false;
}