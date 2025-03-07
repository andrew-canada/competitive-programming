#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, x;
    cin >> n;
    map<int, int> freq;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        freq[x]++;
    }

    ll ans = 0, sum = 0;
    for (auto a : freq)
    {
        ll num = a.second;
        if (num >= 3)
        {
            ans += num * (num - 1) * (num - 2) / 6;
        }
        if (num >= 2)
        {
            ans += num * (num - 1) / 2 * sum;
        }
        sum += num;
    }
    cout << ans << '\n';
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