
int trap(vector<int> &height)
{
    int i = 0, j = height.size() - 1;
    int pmax = 0, smax = 0;
    int totwater = 0;
    while (i < j)
    {
        pmax = max(pmax, height[i]);
        smax = max(smax, height[j]);

        if (pmax <= smax)
            totwater += pmax - height[i++];
        else
            totwater += smax - height[j--];
    }
    return totwater;
}