#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size(), ans = n + m;
    for (int i = 0; i < m; i++)
    {
        int j = i;
        for (const char &c : a)
        {
            if (j < m && c == b[j])
            {
                j++;
            }
        }
        ans = min(ans, n + m - (j - i));
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