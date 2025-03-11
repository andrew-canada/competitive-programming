#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n), p(n), ord(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        ord[i] = i;
    }
    sort(ord.begin(), ord.end(), [&](int x, int y)
         { return p[x] < p[y]; });
    int damage = 0;
    for (int i : ord)
    {
        if (h[i] <= damage)
        {
            continue;
        }
        if (i != ord[0])
        {
            k -= p[i];
        }
        if (k > 0)
        {
            damage += k;
            while (h[i] > damage)
            {
                k -= p[i];
                if (k < 0)
                {
                    break;
                }
                damage += k;
            }
        }
        if (h[i] > damage)
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