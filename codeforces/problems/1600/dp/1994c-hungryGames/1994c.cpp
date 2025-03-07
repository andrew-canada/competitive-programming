#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 2e5;

ll a[mxN + 1];
int dp[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, x;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        partial_sum(a + 1, a + n + 1, a + 1);
        memset(dp, 0, sizeof(dp));
        for (int i = n - 1; i >= 0; --i)
        {
            int q = upper_bound(a, a + n + 1, a[i] + x) - a;
            dp[i] = dp[q] + q - i - 1;
        }
        cout << accumulate(dp, dp + n + 1, 0ll) << '\n';
    }
}