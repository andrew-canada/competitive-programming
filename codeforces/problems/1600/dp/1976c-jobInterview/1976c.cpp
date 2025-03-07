#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 2e5;

int a[2][mxN + 1];
bool types[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int tot = n + m + 1;
        for (int i = 0; i < tot; ++i)
        {
            cin >> a[0][i];
        }
        for (int i = 0; i < tot; ++i)
        {
            cin >> a[1][i];
        }

        int bad = -1, badType = -1;
        array<int, 2> cur;
        ll ans = 0;

        for (int i = 0; i < tot; ++i)
        {
            bool type = 0;
            if (a[0][i] < a[1][i])
            {
                type = 1;
            }
            if (cur[type] == (type == 0 ? n : m))
            {
                type = !type;
                if (bad == -1)
                {
                    bad = i;
                    badType = 1 - type;
                }
            }
            types[i] = type;
            ans += a[type][i];
            cur[type]++;
        }

        vector<ll> res(tot);
        for (int i = 0; i < tot; ++i)
        {
            ll val = ans - a[types[i]][i];
            if (bad != -1 && i < bad && types[i] == badType)
            {
                val = val + a[badType][bad] - a[1 - badType][bad] + a[1 - badType][tot - 1];
            }
            else
            {
                val = val + a[types[i]][tot - 1];
            }
            res[i] = val;
        }
        res[tot - 1] = ans;

        for (ll val : res)
        {
            cout << val << ' ';
        }
        cout << '\n';
    }

    return 0;
}