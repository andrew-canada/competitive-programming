#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 3e5, mxA = 1 << 20;

int a[mxN + 1];
int cnt[2][mxA + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cnt[1][0] = 1;
    int x = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        x ^= a[i];
        ans += cnt[i % 2][x];
        ++cnt[i % 2][x];
    }
    cout << ans << '\n';
}
