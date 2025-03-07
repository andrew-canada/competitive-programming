#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    ll n, m, q, c, p, rem = 0;
    cin >> n >> m >> q;
    vector<ll> pret(m + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> c >> p;
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
    sort(pret.begin(), pret.end());
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

    solve();
}