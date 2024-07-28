#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define INF 0x3f3f3f3f

ll score[1000005];
ll dp[1000005];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    REP(i, 0, n)
    {
        scanf("%lld", &score[i]);
    }
    dp[0] = score[0];
    REP(i, 1, n)
    {
        dp[i] = max(dp[i - 1], score[i]);
    }
    for (int i = k; i < n; i += k)
    {
    }
    printf("%lld", dp[n - 1]);
}