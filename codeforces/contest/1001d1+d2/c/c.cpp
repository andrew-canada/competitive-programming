#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1e3;

ll a[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    ll ans;
    cin >> t;
    while (t--)
    {
        ans = -1e18;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int cur = n;
        for (int i = 1; i <= n; i++)
        {
            ll sum = 0;
            for (int i = 1; i <= cur; i++)
            {
                sum = (sum + a[i]);
            }
            if (i == 1)
            {
                ans = max(ans, sum);
            }
            else
            {
                ans = max(ans, max(sum, (-sum)));
            }
            for (int i = 1; i < cur; i++)
            {
                a[i] = (a[i + 1] - a[i]);
            }
            cur--;
        }
        cout << ans << '\n';
    }
}