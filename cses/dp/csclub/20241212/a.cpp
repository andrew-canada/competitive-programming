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
    for (int i = 2; i <= n; i++)
    {
        ans = (ans * i) % M;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /*
    d*s = 1
    s is multiplicative inverse of d
    s = 1/d

    let s be modular inverse of d
    s * d = 1 M P
    */
    ll t, a, h, l;
    cin >> t;
    while (t--)
    {
        /*
        if p is prime, a^{p-1} = 1 M P
        multiply both sides by a^{-1}
        */
        cin >> a >> h >> l;
        a -= h * l;
        cout << fact(a + h - 1) * mult(fact(h - 1) * fact(a) % M, M - 2) % M << '\n';
    }
}