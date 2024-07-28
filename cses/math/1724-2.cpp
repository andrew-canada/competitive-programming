#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> mat;

const int mxN = 100;
const ll INF = 2e18, NINF = -5e13, M = 1e9 + 7;

mat mult(const mat &a, const mat &b)
{
    mat res(a.size(), vll(b[0].size(), INF));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            for (int k = 0; k < b[0].size(); k++)
            {
                res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    return res;
}

int main()
{
    ll n, m, k, u, v, c;
    cin >> n >> m >> k;
    mat a(n, vll(n, INF)), b(n, vll(n, INF));
    for (int i = 0; i < n; i++)
    {
        a[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> c, --u, --v;
        b[u][v] = min(b[u][v], c);
    }
    while (k)
    {
        if (k & 1)
        {
            a = mult(a, b);
        }
        b = mult(b, b);
        k >>= 1;
    }
    cout << (a[0][n - 1] >= INF ? -1 : a[0][n - 1]);
}