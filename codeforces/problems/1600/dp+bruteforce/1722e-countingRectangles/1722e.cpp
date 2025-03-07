#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e3;

typedef long long ll;

ll a[mxN + 1][mxN + 1];
ll pref[mxN + 1][mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, q;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        memset(a, 0, sizeof(a)), memset(pref, 0, sizeof(pref));
        ll h, w;
        for (int i = 0; i < n; i++)
        {
            cin >> h >> w;
            a[h][w] += h * w;
        }
        for (int i = 1; i <= 1000; i++)
        {
            for (int j = 1; j <= 1000; j++)
            {
                pref[i][j] = pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1] + a[i][j];
            }
        }
        ll hs, ws, hb, wb;
        while (q--)
        {
            cin >> hs >> ws >> hb >> wb;
            cout << pref[hb - 1][wb - 1] - pref[hb - 1][ws] - pref[hs][wb - 1] + pref[hs][ws] << '\n';
        }
    }
}