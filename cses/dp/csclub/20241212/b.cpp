#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e9 + 7;

ll mult(ll b, ll e)
{
    ll ans = 1;
    while (e)
    {
        if (e % 2 == 1)
        {
            ans = (ans * b) % M;
        }
        b = (b * b) % M;
        e /= 2;
    }
    return ans;
}

ll fact(ll n)
{
    ll ans = 1;
    for (ll i = 2; i <= n; i++)
    {
        ans = (ans * i) % M;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, a, h, l;
    cin >> t;
    while (t--)
    {
        cin >> a >> h >> l;
        a -= h * l;
        cout << fact(a + h - 1) * mult(fact(a) * fact(h - 1) % M, M - 2) % M;
    }
}