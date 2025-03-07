#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    ll k, l1, r1, l2, r2;
    cin >> t;
    while (t--)
    {
        cin >> k >> l1 >> r1 >> l2 >> r2;

        ll ans = 0;

        for (ll n = 0;; n++)
        {
            ll kn = pow(k, n);
            if (kn > r2)
            {
                break;
            }

            ll minX = max(l1, (l2 + kn - 1) / kn);
            ll maxX = min(r1, r2 / kn);

            if (minX <= maxX)
            {
                ans += (maxX - minX + 1);
            }
        }

        cout << ans << '\n';
    }
}