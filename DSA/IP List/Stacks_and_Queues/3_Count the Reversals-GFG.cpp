
int countRev(string s)
{
    int oc = 0, cc = 0;
    for (char c : s)
    {
        if (c == '{')
            oc++;
        else
            oc ? oc-- : cc++;
    }
    if ((oc & 1) && (cc & 1))
        return oc / 2 + cc / 2 + 2;
    else if (!(oc & 1) && !(cc & 1))
        return (oc + cc) / 2;
    else
        return -1;
}