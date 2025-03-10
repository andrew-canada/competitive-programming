#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 2, 1), b(n + 2, 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n + 1; i++)
    {
        b[i] = lcm(a[i], a[i - 1]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (gcd(b[i], b[i + 1]) != a[i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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