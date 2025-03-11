#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int l, r, d, u;
    cin >> l >> r >> d >> u;
    cout << (l == r && l == d && d == u ? "YES\n" : "NO\n");
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