#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
	ll x, y, k;
	cin >> x >> y >> k;
	while (k > 0 && x != 1) {
		ll cur = (x / y + 1) * y - x;
        cur = max(1ll, cur);
        cur = min(cur, k);
        x += cur;
		while (x % y == 0) {
			x /= y;
		}
		k -= cur;
	}
	cout << x + k % (y - 1) << '\n';
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