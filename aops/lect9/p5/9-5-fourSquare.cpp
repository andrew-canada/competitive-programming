#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define INF 0x3f3f3f

const int mxN = 5e6 + 1;

int dp[mxN];
int par[mxN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    fill(dp, dp + mxN, INF);
    dp[0] = 0;

    vector<int> sqr;
    for (int i = 1; i * i <= n; i++)
    {
        sqr.pb(i * i);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int sq : sqr)
        {
            if (i < sq)
            {
                break;
            }
            if (dp[i - sq] + 1 < dp[i])
            {
                dp[i] = dp[i - sq] + 1;
                par[i] = sq;
            }
        }
    }

    vector<int> ans;
    int cur = n;
    while (cur > 0)
    {
        ans.pb(par[cur]);
        cur -= par[cur];
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i < ans.size() - 1)
        {
            cout << " ";
        }
    }
}