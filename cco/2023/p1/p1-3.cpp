#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int sums[1000005];
int dp[1000005];
int diff;
int num1;
int num0;
const int MOD = 1e6 + 3;
int states[3005];

ll fact(int n);

int main()
{
    // freopen("p1.in", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    REP(i, 0, n - k + 1)
    {
        scanf("%d", &sums[i]);
    }
    REP(i, 0, n - k)
    {
        diff = sums[i + 1] - sums[i];
        if (diff < 0 && !states[i % k])
        {
            states[i % k] = -1;
            num1++;
        }
        else if (diff > 0 && !states[i % k])
        {
            states[i % k] = 1;
            num0++;
        }
    }
    ll n1 = fact(k - num1 - num0);
    ll k1 = fact(sums[0] - num1);
    ll d1 = fact(k - num0 - sums[0]);
    printf("%d", (n1 / k1 / d1));
}

ll fact(int n)
{
    ll result = 1;
    for (int i = 2; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}