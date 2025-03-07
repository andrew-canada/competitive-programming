#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 5e3;

ll a[mxN], b[mxN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }

    ll initial = 0;
    for (int i = 0; i < n; ++i)
    {
        initial += a[i] * b[i];
    }

    ll ans = initial;

    for (int mid = 0; mid < n; ++mid)
    {
        ll cur = initial;
        for (int l = mid, r = mid; l >= 0 && r < n; --l, ++r)
        {
            if (l != r)
            {
                cur -= a[l] * b[l] + a[r] * b[r];
                cur += a[l] * b[r] + a[r] * b[l];
            }
            ans = max(ans, cur);
        }

        cur = initial;
        for (int l = mid, r = mid + 1; l >= 0 && r < n; --l, ++r)
        {
            cur -= a[l] * b[l] + a[r] * b[r];
            cur += a[l] * b[r] + a[r] * b[l];
            ans = max(ans, cur);
        }
    }

    cout << ans << '\n';
}