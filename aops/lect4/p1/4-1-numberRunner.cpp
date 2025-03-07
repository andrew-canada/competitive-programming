#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mxK = 1e3;

ll dp1[mxK + 1], dp2[mxK + 1], ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, val;
    cin >> n >> k >> val;
    dp1[0] = val, dp1[1] = -val;
    for (int i = 1; i < n; i++)
    {
        cin >> val;
        dp2[0] = dp1[0] + val;
        for (int j = 1; j <= k; j++)
        {
            dp2[j] = (j & 1 ? max(dp1[j] - val, dp1[j - 1] - val) : max(dp1[j] + val, dp1[j - 1] + val));
        }
        for (int j = 0; j <= k; j++)
        {
            dp1[j] = dp2[j];
        }
    }
    for (int i = 0; i <= k; i++)
    {
        ans = max(ans, dp1[i]);
    }
    cout << ans;
}