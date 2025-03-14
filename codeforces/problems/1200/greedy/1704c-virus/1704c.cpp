#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, x, y, l, diff;
    cin >> n >> x >> y;
    l = n - 1;
    while ((y - x) % l)
    {
        l--;
    }
    diff = (y - x) / l;
    while (y - (n - 1) * diff < 1)
    {
        y += diff;
    }
    for (int i = 0; i < n; i++)
    {
        cout << y - (i * diff) << " ";
    }
    cout << '\n';
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