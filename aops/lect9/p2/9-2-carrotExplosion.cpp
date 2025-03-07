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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll c, w, a, m;
    cin >> c >> w >> a >> m;
    if (m == 1)
    {
        cout << c + (w % M) * a % M;
        exit(0);
    }

    if (c + a > c * m)
    {
        c = (c + a) % M;
        w -= 1;
    }
    cout << c * mult(m, w) % M;
}