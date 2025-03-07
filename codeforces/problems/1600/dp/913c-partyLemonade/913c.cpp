#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        c[i + 1] = min(c[i + 1], 2 * c[i]);
    }
    ll ans = (ll)4e18;
    ll sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int need = l / (1 << i);
        sum += (ll)need * c[i];
        l -= need << i;
        ans = min(ans, sum + (l > 0) * c[i]);
    }
    cout << ans << '\n';
}