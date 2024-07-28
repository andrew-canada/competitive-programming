#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define INF 0x3f3f3f3f

const int maxn = 1e6;

int c[maxn + 1];
int dp[maxn + 1];

int main()
{
    int x, n;
    scanf("%d%d", &x, &n);
    REP(i, 0, n - 1)
    {
        scanf("%d", &c[i]);
    }
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    REP(i, 0, n - 1)
    {
        REP(j, 0, x)
        {
            if (j >= c[i])
            {
                dp[j] = min(dp[j], dp[j - c[i]] + 1);
            }
        }
    }
    printf("%d\n", dp[x] == INF ? -1 : dp[x]);
}