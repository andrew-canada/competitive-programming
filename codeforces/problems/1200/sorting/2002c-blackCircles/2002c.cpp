#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f

ll dist(ll xs, ll ys, ll xt, ll yt)
{
    return (xt - xs) * (xt - xs) + (yt - ys) * (yt - ys);
}

void solve()
{
    ll n, xs, ys, xt, yt;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    cin >> xs >> ys >> xt >> yt;
    for (int i = 0; i < n; i++)
    {
        if (dist(xt, yt, x[i], y[i]) <= dist(xt, yt, xs, ys))
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}