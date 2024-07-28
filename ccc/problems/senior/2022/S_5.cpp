#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 2e5;

vector<int> adjL[mxN + 1];
bool part[mxN + 1];
int cost[mxN + 1];
ll dp[mxN + 1][3];

void dfs(int cur, int par)
{
    for (int i : adjL[cur])
    {
        if (i != par)
        {
            dfs(i, cur);
        }
    }
    if (part[cur])
    {
        dp[cur][0] = INF, dp[cur][1] = 0, dp[cur][2] = cost[cur];
        for (int i : adjL[cur])
        {
            if (i != par)
            {
                dp[cur][1] += dp[i][1];
                dp[cur][2] += dp[i][0];
            }
        }
    }
    else
    {
        ll inflC = 0, parC = 0;
        for (int i : adjL[cur])
        {
            if (i != par)
            {
                inflC += dp[i][0];
                parC += dp[i][1];
            }
        }
        dp[cur][0] = min(parC, inflC + cost[cur]), dp[cur][1] = INF, dp[cur][2] = INF;
        for (int i : adjL[cur])
        {
            if (i != par)
            {
                dp[cur][1] = min(dp[cur][1], parC - dp[i][1] + dp[i][2]);
                dp[cur][2] = min(dp[cur][2], inflC - dp[i][0] + dp[i][2] + cost[cur]);
            }
        }
    }
    dp[cur][1] = min(dp[cur][1], dp[cur][2]);
    dp[cur][0] = min(dp[cur][0], dp[cur][1]);
}

int main()
{
    int n;
    cin >> n;
    int a, b;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        adjL[a].pb(b), adjL[b].pb(a);
    }
    char c;
    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        part[i] = (c == 'Y');
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }
    dfs(1, -1);
    cout << dp[1][1];
}