#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> psa(n + 1, 0), psaMax(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        psa[i] = psa[i - 1] + a;
        psaMax[i] = max(psaMax[i - 1], 1LL * a);
    }
    while (q--)
    {
        int k;
        cin >> k;
        cout << psa[upper_bound(psaMax.begin(), psaMax.end(), k) - psaMax.begin() - 1] << " ";
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