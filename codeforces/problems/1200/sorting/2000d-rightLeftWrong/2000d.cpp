#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n;
    cin >> t;
    while (t--)
    {
        ll ans = 0;
        string s;
        cin >> n;
        vector<ll> a(n + 1, 0);
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        cin >> s;
        s.insert(s.begin(), ',');
        ll l = 1, r = n;
        while (l <= r)
        {
            while (l <= r && s[l] != 'L')
            {
                l++;
            }
            while (l <= r && s[r] != 'R')
            {
                r--;
            }
            if (l < r)
            {
                ans += a[r] - a[l - 1];
            }
            l++, r--;
        }
        cout << ans << '\n';
    }
}