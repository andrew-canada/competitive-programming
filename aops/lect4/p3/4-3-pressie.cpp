#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxL = 1e4;

struct peg
{
    ll n, p, t;
};

peg pegs[mxL + 1];
ll dp[mxL + 1], ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll l, k;
    cin >> l >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> pegs[i].n >> pegs[i].p >> pegs[i].t;
    }

    fill(dp, dp + l + 1, 0);

    for (int i = 0; i < k; i++)
    {
        ll n = pegs[i].n;
        ll p = pegs[i].p;
        ll t = pegs[i].t;

        for (ll m = 1; n > 0; m <<= 1)
        {
            ll count = min(m, n);
            n -= count;
            for (int j = l; j >= count * t; j--)
            {
                dp[j] = max(dp[j], dp[j - count * t] + count * p);
            }
        }
    }

    for (int j = 0; j <= l; j++)
    {
        ans = max(ans, dp[j]);
    }

    cout << ans << endl;

    return 0;
}