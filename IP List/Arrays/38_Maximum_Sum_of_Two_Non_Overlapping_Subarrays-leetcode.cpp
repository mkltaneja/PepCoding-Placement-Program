
// int maxSumTwoNoOverlap(vector<int> &A, int L, int M)
// {
//     int n = A.size();
//     vector<int> psmax(n, 0);
//     vector<int> ssmax(n, 0);

//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         sum += A[i];
//         if (i >= L)
//             sum -= A[i - L];
//         if (i >= L - 1)
//         {
//             if (i == L - 1)
//                 psmax[i] = sum;
//             else
//                 psmax[i] = max(psmax[i - 1], sum);
//         }
//         else
//             psmax[i] = -1;
//     }
//     sum = 0;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         sum += A[i];
//         if (n - i - 1 >= L)
//             sum -= A[i + L];
//         if (n - i - 1 >= L - 1)
//         {
//             if (n - i - 1 == L - 1)
//                 ssmax[i] = sum;
//             else
//                 ssmax[i] = max(ssmax[i + 1], sum);
//         }
//         else
//             ssmax[i] = -1;
//     }

//     int maxsum = 0;
//     sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         sum += A[i];
//         if (i >= M)
//             sum -= A[i - M];
//         if (i >= M - 1)
//         {
//             int pmax = -1, smax = -1;
//             if (i - M >= 0)
//                 pmax = psmax[i - M];
//             if (i + 1 < n)
//                 smax = ssmax[i + 1];
//             maxsum = max({maxsum, sum + max(pmax, smax)});
//         }
//     }
//     return maxsum;
// }

#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int i = 0, j = height.size() - 1;
    int pmax = 0, smax = 0;
    int totwater = 0;
    while (i < j)
    {
        int pmax = max(pmax, height[i]);
        int smax = max(smax, height[j]);

        if (pmax <= smax)
            totwater += pmax - height[i++];
        else
            totwater += smax - height[j--];

        // cout<<i<<", "<<j<<endl;
    }
    return totwater;
}

int main()
{
    vector<int> h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << trap(h) << endl;
}
