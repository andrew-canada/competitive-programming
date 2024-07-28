#include <stdio.h>
#include <cstring>

#define REP(i, a, b) for (int i = int(a); i <= int(b - 1); i++)
#define min(a, b) a < b ? a : b

typedef long long ll;

int n;

int val;
ll dp[405][405];
ll psa[405];

int main()
{
    scanf("%d", &n);
    memset(dp, 2, sizeof(dp));
    REP(i, 0, n)
    {
        scanf("%d", &val);
        psa[i] = val + psa[i - 1];
        dp[i][i] = 0;
    }
    REP(len, 2, n + 1)
    {
        REP(l, 0, n - len + 1)
        {
            ll r = l + len - 1;
            REP(i, l + 1, r + 1)
            {
                dp[l][r] = min(dp[l][r], dp[l][i - 1] + dp[i][r]);
            }
            dp[l][r] += psa[r] - psa[l - 1];
        }
    }
    printf("%lld", dp[0][n - 1]);
}