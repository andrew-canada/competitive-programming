#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

const int MAXN = 1000005;
int sums[MAXN];
int dp[3005][3005];
int diff;
int num1;
int num0;
const int MOD = 1e6 + 3;
int states[3005];
ll fact[MAXN];
ll inv[MAXN];

ull nCk(int n, int k);
void precomp(int n);
ull power(ull x, ull y);

int main()
{
    // freopen("p1.in", "r", stdin);
    // freopen("p1.out", "w", stdout);
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
    precomp(n);
    printf("%lld", nCk(k - num1 - num0, sums[0] - num1));
}

ull nCk(int n, int k)
{
    return (fact[n] * inv[k] % MOD * inv[n - k]) % MOD;
}

void precomp(int n)
{
    fact[0] = fact[1] = 1;
    inv[0] = inv[1] = 1;
    REP(i, 2, n + 2)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = power(fact[i], MOD - 2);
    }
}

ull power(ull x, ull y)
{
    ull res = 1;
    x %= MOD;
    while (y > 0)
    {
        if (y & 1)
        {
            res = (res * x) % MOD;
        }
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}