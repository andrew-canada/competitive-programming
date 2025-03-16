#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, ans;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ans = n = unique(a.begin(), a.end()) - a.begin();
    for (int i = 0; i < n - 2; i++)
    {
        ans -= a[i] < a[i + 1] && a[i + 1] < a[i + 2];
        ans -= a[i] > a[i + 1] && a[i + 1] > a[i + 2];
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