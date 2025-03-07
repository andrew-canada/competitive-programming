#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

ll r[mxN + 1], c[mxN + 1], rSum[mxN + 1], cSum[mxN + 1];
bool tar[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q, x;
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> c[i];
    }

    ll initial = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            initial += r[i] * c[j];
            rSum[i] += r[i] * c[j];
            cSum[j] += r[i] * c[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tar[initial - rSum[i] - cSum[j] + r[i] * c[j]] = true;
        }
    }

    while (q--)
    {
        cin >> x;
        cout << (tar[x] ? "YES\n" : "NO\n");
    }
}