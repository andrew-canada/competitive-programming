#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

const int mxM = 2e5;

ll n, m, q, c, p, rem = 0, query, pen, val;
ll pret[mxM + 1];
array<ll, 2> inputPens[mxM + 1];

void solve()
{
    memset(pret, 0, sizeof(pret));
    for (int i = 1; i <= n; i++)
    {
        c = inputPens[i][0], p = inputPens[i][1];
        if (pret[c])
        {
            if (p >= pret[c])
            {
                rem = max(rem, pret[c]);
                pret[c] = p;
            }
            else
            {
                rem = max(rem, p);
            }
        }
        else
        {
            pret[c] = p;
        }
    }
    sort(pret, pret + m + 1);
    ll ans = 0;
    for (int i = 2; i <= m; i++)
    {
        ans += pret[i];
    }
    ans += max(pret[1], rem);
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> inputPens[i][0] >> inputPens[i][1];
    }
    solve();
    while (q--)
    {
        ll prev;
        cin >> query >> pen >> val;
        if (query == 1)
        {
            prev = inputPens[pen][0];
            inputPens[pen][0] = val;
        }
        else
        {
            prev = inputPens[pen][1];
            inputPens[pen][1] = val;
        }
        solve();
        if (query == 1)
        {
            inputPens[pen][0] = prev;
        }
        else
        {
            inputPens[pen][1] = prev;
        }
    }
}