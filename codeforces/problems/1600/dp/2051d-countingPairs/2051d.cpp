#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, x, y;
    cin >> t;
    while (t--)
    {
        cin >> n >> x >> y;
        vector<int> a(n);
        ll ans = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            int l = lower_bound(a.begin(), a.end(), sum - a[i] - y) - a.begin();
            int r = upper_bound(a.begin(), a.end(), sum - a[i] - x) - a.begin() - 1;
            l = max(l, i + 1);
            ans += max(r - l + 1, 0);
        }
        cout << ans << '\n';
    }
}