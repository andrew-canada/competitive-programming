#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e9 + 7;

ll mult(ll b, ll e)
{
    ll ans = 1;
    while (e)
    {
        if (e & 1)
        {
            ans = (ans * b) % M;
        }
        e >>= 1;
        b = (b * b) % M;
    }
    return ans;
}

ll fact(ll n)
{
    ll val = 1;
    for (int i = 2; i <= n; i++)
    {
        val = (val * i) % M;
    }
    return val;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, a, h, l;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> h >> l;
        a -= h * l;
        cout << (fact(a + h - 1) % M) * mult((fact(h - 1) % M) * (fact(a) % M) % M, M - 2) % M << '\n';
    }
}