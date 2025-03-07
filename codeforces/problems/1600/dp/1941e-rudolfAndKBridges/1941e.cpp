#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 100, mxM = 2e5;

ll rowCost[mxN + 1], depth[mxM + 1], dp[mxM + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m, k, d;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k >> d;
        for (int i = 0; i < n; i++)
        {
            multiset<ll> mst = {1};
            dp[0] = 1;
            cin >> depth[0];

            for (int j = 1; j < m - 1; j++)
            {
                cin >> depth[j];
                dp[j] = *mst.begin() + depth[j] + 1;
                if (j - d - 1 >= 0)
                {
                    mst.erase(mst.find((dp[j - d - 1])));
                }
                mst.insert(dp[j]);
            }
            cin >> depth[m - 1];
            dp[m - 1] = 1 + *mst.begin();
            rowCost[i] = dp[m - 1];
        }

        ll cur = 0;
        for (int i = 0; i < k; i++)
        {
            cur += rowCost[i];
        }

        ll ans = cur;
        for (int i = k; i < n; i++)
        {
            cur += rowCost[i] - rowCost[i - k];
            ans = min(cur, ans);
        }
        cout << ans << '\n';
    }
}