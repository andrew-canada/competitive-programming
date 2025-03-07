#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(ll l, ll r, ll k)
{
    if (r - l + 1 < k)
    {
        return 0;
    }

    ll m = (l + r) / 2;
    ll val = 0;

    if ((r - l + 1) % 2 == 1)
    {
        val += m;
        val += solve(l, m - 1, k);
        val += solve(m + 1, r, k);
    }
    else
    {
        val += solve(l, m, k);
        val += solve(m + 1, r, k);
    }

    return val;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << solve(1, n, k) << '\n';
    }
}