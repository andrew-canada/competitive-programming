#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    ll r;
    cin >> r;
    if (r < 5 || r % 2 == 0)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "1 " << (r - 3) / 2 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--)
    {
        solve();
    }
}