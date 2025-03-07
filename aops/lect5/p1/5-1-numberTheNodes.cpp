#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

const int mxN = 1e4;

int n, d, k, a, b;
vector<int> adjL[mxN + 1];
int dp[mxN + 1][10];

void dfs(int cur, int par)
{
    for (int i = 1; i <= d; i++)
    {
        dp[cur][i] = i;
    }
    for (int next : adjL[cur])
    {
        if (next == par)
        {
            continue;
        }
        dfs(next, cur);
        for (int i = 1; i <= d; i++)
        {
            int best = INF;
            for (int j = 1; j <= d; j++)
            {
                if (i != j)
                {
                    best = min(best, dp[next][j]);
                }
            }
            dp[cur][i] += best;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> k;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adjL[a].pb(b);
        adjL[b].pb(a);
    }

    dfs(1, -1);
    int ans = INF;
    for (int i = 1; i <= d; i++)
    {
        ans = min(ans, dp[1][i]);
    }
    cout << ans;
}