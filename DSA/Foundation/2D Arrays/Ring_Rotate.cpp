#include <iostream>

#include <vector>

using namespace std;

vector<long> Ring(long sr, long sc, long er, long ec, vector<vector<long>> &arr)
{
    long n = 2 * (er - sr) + 2 * (ec - sc);
    vector<long> ring(n);
    // cout<<ring.size()<<endl;
    long k = 0;

    for (long i = sr; i < er; i++)
        ring[k++] = arr[i][sc];
    for (long i = sc; i < ec; i++)
        ring[k++] = arr[er][i];
    for (long i = er; i > sr; i--)
        ring[k++] = arr[i][ec];
    for (long i = ec; i > sc; i--)
        ring[k++] = arr[sr][i];

    return ring;
}

void Rotate(long r, long n, vector<long> &arr)
{
    vector<long> temp(arr.begin(), arr.begin() + (n - r));
    arr.erase(arr.begin(), arr.begin() + (n - r));
    arr.insert(arr.end(), temp.begin(), temp.end());
}

void ring_recover(long sr, long sc, long er, long ec, vector<long> &ring, vector<vector<long>> &arr)
{
    long k = 0;

    for (long i = sr; i < er; i++)
        arr[i][sc] = ring[k++];
    for (long i = sc; i < ec; i++)
        arr[er][i] = ring[k++];
    for (long i = er; i > sr; i--)
        arr[i][ec] = ring[k++];
    for (long i = ec; i > sc; i--)
        arr[sr][i] = ring[k++];
}

void ring_rotate(long n, long m, vector<vector<long>> &arr, long s, long r)
{
    long sr = s - 1, sc = s - 1, er = n - s, ec = m - s;
    vector<long> ring = Ring(sr, sc, er, ec, arr);
    long sz = ring.size();
    // cout<<ring.size()<<endl;
    // for(long i : ring)
    //     cout<<i<<" ";

    r = r % sz;
    if (r < 0)
        r += sz;

    Rotate(r, sz, ring);
    ring_recover(sr, sc, er, ec, ring, arr);

    for (long i = 0; i < n; i++)
    {
        for (long j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    long n, m, s, r;
    cin >> n >> m;
    vector<vector<long>> arr(n, vector<long>(m));
    for (long i = 0; i < n; i++)
        for (long j = 0; j < m; j++)
            cin >> arr[i][j];
    cin >> s >> r;

    ring_rotate(n, m, arr, s, r);
}