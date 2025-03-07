// this doesn't work

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

ll modexp(ll exp, ll base)
{
    ll curr = 1;
    ll modded_m_power = base;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            curr *= modded_m_power;
            curr %= MOD;
        }
        exp /= 2;
        modded_m_power *= modded_m_power; // square
        modded_m_power %= MOD;
    }
    return curr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, h, l;
    cin >> a >> h >> l;
    ll n = a - l * h + h - 1;
    if (n == 0)
    {
        cout << 1 << '\n';
        exit(0);
    }
    ll k = h - 1;
    ll num = 1;
    ll denom = 1;
    // do n! / k!
    for (int i = k + 1; i <= n; ++i)
    {
        num *= i;
        num %= MOD;
    }
    // divide out (n-k)!
    for (int i = 2; i <= (n - k); ++i)
    {
        denom *= i;
        denom %= MOD;
    }
    // find inverse
    ll inv = modexp(MOD - 2, denom);
    cout << (num * inv) % MOD << '\n';
}