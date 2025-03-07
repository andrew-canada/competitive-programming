#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll M = 1e9 + 7;

ll binpow(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll MInverse(ll n, ll p)
{
    return binpow(n, p - 2, p);
}

ll nCrMPFermat(ll n, ll r, ll p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    ll fac[n + 1];
    fac[0] = 1;
    for (ll i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * MInverse(fac[r], p) % p * MInverse(fac[n - r], p) % p) % p;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    ll a = n + 2 * m - 1, b = 2 * m;
    cout << nCrMPFermat(a, b, M);
}