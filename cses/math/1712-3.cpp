#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e9 + 7;

ll mult(ll b, ll e, ll m)
{
    ll a = 1;
    while (e)
    {
        if (e & 1)
        {
            a = (a * b) % m;
        }
        e >>= 1;
        b = (b * b) % m;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0, a, b, c; i < n; i++)
    {
        cin >> a >> b >> c;
        ll x = mult(b, c, M - 1);
        cout << mult(a, x, M) << '\n';
    }
}