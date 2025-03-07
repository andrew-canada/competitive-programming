#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f

void solve()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    cout << 2 * min(a + x + max(b, y), b + y + max(a, x));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}