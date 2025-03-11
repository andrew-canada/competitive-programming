#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2)
        {
            if (a[i] % 2 == 1)
            {
                ans -= a[i];
            }
        }
        else
        {
            if (a[i] % 2 == 0)
            {
                ans += a[i];
            }
        }
    }
    if (ans == 0)
    {
        cout << "Tie\n";
    }
    else if (ans > 0)
    {
        cout << "Alice\n";
    }
    else
    {
        cout << "Bob\n";
    }
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