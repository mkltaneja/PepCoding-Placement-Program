
string getSmallest(long long N)
{
    if (N == 1)
        return "1";
    string ans = "";
    for (long long x = 9; N != 1 && x >= 2; x--)
    {
        while (N != 1 && N % x == 0)
        {
            N /= x;
            ans += x + '0';
        }
    }
    reverse(ans.begin(), ans.end());

    return (N == 1) ? ans : "-1";
}