#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> mat;

const int mxN = 100;
const ll INF = 5e13, NINF = -5e13, M = 1e9 + 7;

mat mult(const mat &a, const mat &b)
{
    mat res(a.size(), vll(b[0].size()));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            for (int k = 0; k < b[0].size(); k++)
            {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % M) % M;
            }
        }
    }
    return res;
}

int main()
{
    int n, m, k, u, v;
    cin >> n >> m >> k;
    mat a(n, vll(n)), b(n, vll(n));
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v, --u, --v;
        b[u][v]++;
    }
    for (int i = 0; i < n; i++)
    {
        a[i][i] = 1;
    }
    while (k)
    {
        if (k & 1)
        {
            a = mult(a, b);
        }
        k >>= 1;
        b = mult(b, b);
    }
    cout << a[0][n - 1];
}