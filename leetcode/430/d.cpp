#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int MAXN = 100000;

vector<long long> fact(MAXN + 1), invFact(MAXN + 1);

int modExp(int base, int exp, int mod)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (1LL * result * base) % mod;
        }
        base = (1LL * base * base) % mod;
        exp /= 2;
    }
    return result;
}

void precomputeFactorials()
{
    fact[0] = 1;
    for (int i = 1; i <= MAXN; ++i)
    {
        fact[i] = (1LL * fact[i - 1] * i) % M;
    }
    invFact[MAXN] = modExp(fact[MAXN], M - 2, M);
    for (int i = MAXN - 1; i >= 0; --i)
    {
        invFact[i] = (1LL * invFact[i + 1] * (i + 1)) % M;
    }
}

int binomialCoeff(int n, int k)
{
    if (k > n || k < 0)
        return 0;
    return (1LL * fact[n] * invFact[k] % M * invFact[n - k] % M) % M;
}

int countGoodArrays(int n, int m, int k)
{
    precomputeFactorials();
    int result = 0;
    for (int i = 0; i <= k; ++i)
    {
        int ways = binomialCoeff(n - 1, i);
        int remaining = n - 1 - i;
        int power = modExp(m - 1, remaining, M);
        result = (result + 1LL * ways * power % M) % M;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int ans = countGoodArrays(n, m, k);
    cout << ans << endl;

    return 0;
}