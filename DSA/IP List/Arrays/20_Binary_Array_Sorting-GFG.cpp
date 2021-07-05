void binSort(int A[], int N)
{
    int i = 0, j = 0;
    while (i < N)
    {
        if (A[i] == 0)
            swap(A[i], A[j++]);
        i++;
    }
}