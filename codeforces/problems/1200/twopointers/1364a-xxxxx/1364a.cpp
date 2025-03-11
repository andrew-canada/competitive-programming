#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, x, a, l = -1, r, sum = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        sum += a;
        if (a % x)
        {
            if (l == -1)
            {
                l = i;
            }
            r = i;
        }
    }
    if (l == -1)
    {
        cout << "-1\n";
    }
    else if (sum % x)
    {
        cout << n << '\n';
    }
    else
    {
        cout << n - min(l + 1, n - r) << '\n';
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