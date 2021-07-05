#include <iostream>
#include <vector>
using namespace std;

void multiplication(int n1, int m1, vector<vector<int>> &a, int n2, int m2, vector<vector<int>> &b)
{
    vector<vector<int>> c(n1, vector<int>(m2, 0));

    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m2; j++)
            for (int k = 0; k < n2; k++)
                c[i][j] += a[i][k] * b[k][j];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n1, m1, n2, m2;
    cin >> n1 >> m1;
    vector<vector<int>> a(n1, vector<int>(m1));
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m1; j++)
            cin >> a[i][j];

    cin >> n2 >> m2;
    vector<vector<int>> b(n2, vector<int>(m2));
    for (int i = 0; i < n2; i++)
        for (int j = 0; j < m2; j++)
            cin >> b[i][j];
    if (m1 != n2)
        cout << "Invalid input";
    else
        multiplication(n1, m1, a, n2, m2, b);
}