#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e9 + 7;

ll mult(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
        {
            ans = (ans * x) % M;
        }
        x = (x * x) % M;
        y >>= 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> fact(n + 2 * m);
    fact[0] = 1;
    for (int i = 1; i <= n + 2 * m - 1; i++)
    {
        fact[i] = fact[i - 1] * i % M;
    }
    cout << fact[n + 2 * m - 1] * mult(fact[2 * m] * fact[n - 1] % M, M - 2) % M;
}