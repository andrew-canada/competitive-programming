#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int cur = 0, maxVal = 0;
        for (int j = 1; j < i; j++)
        {
            cur += j * j;
            maxVal = max(j * j, maxVal);
        }
        for (int j = i; j <= n; j++)
        {
            cur += j * (n + i - j);
            maxVal = max(j * (n + i - j), maxVal);
        }
        cur -= maxVal;
        ans = max(ans, cur);
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